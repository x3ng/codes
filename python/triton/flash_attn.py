import torch
import triton
import triton.language as tl

SMEM = 1 * 1024
seq_len = 33
head_dim = 55

q = torch.rand(seq_len, head_dim)
k = torch.rand(seq_len, head_dim)
v = torch.rand(seq_len, head_dim)


def attention(q: torch.Tensor, k: torch.Tensor, v: torch.Tensor):
    head_dim = q.shape[1]
    scale = 1.0 / torch.sqrt(torch.tensor(head_dim))
    return torch.softmax(q @ k.transpose(-1, -2) * scale, dim=-1) @ v



def attention_tile_sizes(q: torch.Tensor):
    """Choose tiles using the paper's simplified SRAM budget (SMEM in bytes).

    This models the algorithm's storage budget, not PyTorch allocations or
    the shared-memory/register usage of the Triton kernel.
    """
    head_dim = q.shape[1]
    if head_dim <= 0:
        raise ValueError("Head dimension must be positive")
    capacity = SMEM // q.element_size()
    bc = capacity // (4 * head_dim)
    if bc < 1:
        raise ValueError("SMEM budget is too small for one attention tile")
    br = min(bc, head_dim)
    return br, bc

def flash_attn_v1(q: torch.Tensor, k: torch.Tensor, v: torch.Tensor):
    q_len, head_dim = q.shape
    kv_len = k.shape[0]
    scale = 1.0 / torch.sqrt(torch.tensor(head_dim))
    br, bc = attention_tile_sizes(q)
    m = torch.full((q_len, 1), -float("inf"))
    l = torch.zeros(q_len, 1)
    o = torch.zeros(q_len, head_dim)
    for c in range(0, (kv_len + bc - 1) // bc):
        ck, cv = (
            k[bc * c : min(bc * (c + 1), kv_len), :],
            v[bc * c : min(bc * (c + 1), kv_len), :],
        )
        for r in range(0, (q_len + br - 1) // br):
            rq = q[br * r : min(br * (r + 1), q_len), :]
            ro = o[br * r : min(br * (r + 1), q_len), :]
            rm = m[br * r : min(br * (r + 1), q_len), :]
            rl = l[br * r : min(br * (r + 1), q_len), :]

            s = rq @ ck.transpose(-1, -2) * scale

            lm = s.max(dim=-1).values
            lm = torch.max(rm, lm.unsqueeze(dim=-1))
            ms = torch.exp(rm - lm)

            p = torch.exp(s - lm)

            ll = torch.sum(p, dim=-1).unsqueeze(dim=-1)
            ll += rl * ms

            o[br * r : min(br * (r + 1), q_len), :] = (ro * ms * rl + p @ cv) / ll
            m[br * r : min(br * (r + 1), q_len), :] = lm
            l[br * r : min(br * (r + 1), q_len), :] = ll

    return o


def flash_attn_v2(q: torch.Tensor, k: torch.Tensor, v: torch.Tensor):
    q_len, head_dim = q.shape
    kv_len = k.shape[0]
    scale = 1.0 / torch.sqrt(torch.tensor(head_dim))
    br, bc = attention_tile_sizes(q)

    o = torch.zeros(q_len, head_dim)
    l = torch.empty(q_len, 1)

    for r in range(0, (q_len + br - 1) // br):
        rs = br * r
        re = min(br * (r + 1), q_len)
        rl = re - rs
        rq = q[rs:re, :]
        rm = torch.full((rl, 1), -float("inf"))
        rl = torch.zeros_like(rm)
        for c in range(0, (kv_len + bc - 1) // bc):
            ck, cv = (
                k[bc * c : min(bc * (c + 1), kv_len), :],
                v[bc * c : min(bc * (c + 1), kv_len), :],
            )

            s = rq @ ck.transpose(-1, -2) * scale

            lm = torch.max(s, dim=-1).values
            lm = torch.max(lm.unsqueeze(dim=-1), rm)
            ms = torch.exp(rm - lm)

            p = torch.exp(s - lm)

            ll = torch.sum(p, dim=-1).unsqueeze(dim=-1)
            ll += rl * ms

            o[rs:re, :] = o[rs:re, :] * ms + p @ cv
            rm = lm
            rl = ll

        l[rs:re, :] = rl

    o /= l

    return o


@triton.jit
def fa_v2_kernel(
    q,
    k,
    v,
    o,
    scale,
    Nq: tl.constexpr,
    Nkv: tl.constexpr,
    D: tl.constexpr,
    BLOCK_D: tl.constexpr,
    BR: tl.constexpr,
    BC: tl.constexpr,
    DTYPE: tl.constexpr,
    CAUSAL: tl.constexpr,
):
    pid = tl.program_id(0)
    off_q = pid * BR + tl.arange(0, BR)
    off_d = tl.arange(0, BLOCK_D)

    rq = tl.load(
        q + off_q[:, None] * D + off_d[None, :],
        mask=(off_q[:, None] < Nq) & (off_d[None, :] < D),
        other=0.0,
    ).to(DTYPE)
    # Keep online softmax statistics and the output accumulator in FP32.
    ro = tl.zeros((BR, BLOCK_D), dtype=tl.float32)
    rm = tl.full((BR,), -float("inf"), dtype=tl.float32)
    rl = tl.zeros((BR,), dtype=tl.float32)

    for c in range(0, tl.cdiv(Nkv, BC)):
        off_kv = c * BC + tl.arange(0, BC)
        kv_mask = (off_kv[:, None] < Nkv) & (off_d[None, :] < D)
        ck = tl.load(
            k + off_kv[:, None] * D + off_d[None, :],
            mask=kv_mask,
            other=0.0,
        ).to(DTYPE)
        cv = tl.load(
            v + off_kv[:, None] * D + off_d[None, :],
            mask=kv_mask,
            other=0.0,
        ).to(DTYPE)

        s = tl.dot(rq, tl.trans(ck)) * scale
        valid = off_kv[None, :] < Nkv
        if CAUSAL:
            valid = valid & (off_q[:, None] >= off_kv[None, :])
        s = tl.where(valid, s, -float("inf"))

        pm = rm
        rm = tl.maximum(rm, tl.max(s, axis=1))
        ms = tl.exp(pm - rm)
        p = tl.exp(s - rm[:, None])
        rl = rl * ms + tl.sum(p, axis=1)
        ro = ro * ms[:, None] + tl.dot(p.to(DTYPE), cv)

    ro = ro / rl[:, None]
    tl.store(
        o + off_q[:, None] * D + off_d[None, :],
        ro,
        mask=(off_q[:, None] < Nq) & (off_d[None, :] < D),
    )


def fa_v2_tl(q: torch.Tensor, k: torch.Tensor, v: torch.Tensor, causal: bool = False):
    if any(t.ndim != 2 for t in (q, k, v)):
        raise ValueError("Expected 2D Q, K, V tensors")
    q_len, head_dim = q.shape
    kv_len = k.shape[0]
    if k.shape != v.shape or k.shape[1] != head_dim:
        raise ValueError("Q, K, V must share a head dimension; K and V must share a shape")
    if head_dim == 0 or kv_len == 0:
        raise ValueError("Head dimension and KV length must be positive")
    interpret = triton.knobs.runtime.interpret
    if any(t.device != q.device for t in (q, k, v)):
        raise ValueError("Q, K, V must be on the same device")
    if not interpret and not q.is_cuda:
        raise ValueError("Q, K, V must be on CUDA unless TRITON_INTERPRET=1")
    if q.dtype not in (torch.float16, torch.bfloat16) or any(
        t.dtype != q.dtype for t in (k, v)
    ):
        raise ValueError("Q, K, V must share dtype float16 or bfloat16")
    if any(not t.is_contiguous() for t in (q, k, v)):
        raise ValueError("This kernel requires contiguous Q, K, V tensors")

    o = torch.empty_like(q)
    if q_len == 0:
        return o
    # tl.arange sizes must be powers of two; dot tiles need sufficient dimensions.
    block_d = max(16, triton.next_power_of_2(head_dim))
    br, bc = 32, 32
    # Triton accepts ordinary Python values for constexpr launch parameters.
    # ty treats these JIT annotations as ordinary Python parameter types.
    fa_v2_kernel[(triton.cdiv(q_len, br),)](
        q,
        k,
        v,
        o,
        head_dim ** -0.5,
        Nq=q_len,
        Nkv=kv_len,
        D=head_dim,
        BLOCK_D=block_d,
        BR=br,
        BC=bc,
        DTYPE=tl.float16 if q.dtype == torch.float16 else tl.bfloat16,
        CAUSAL=causal,
    )
    return o


## ==================== test ====================##

methods = {
    "flash_attn_v1": flash_attn_v1,
    "flash_attn_v2": flash_attn_v2,
}


def run_test(method_dict, q, k, v):
    ref = attention(q, k, v)
    result = {}
    for name, fn in method_dict.items():
        out = fn(q, k, v)
        max_diff = torch.max(torch.abs(ref - out)).item()
        result[name] = {
            "max_diff": max_diff,
            "output": out,
        }
        print(f"{name:<18s} | max_diff = {max_diff:.3e}")
    return result


if __name__ == "__main__":
    test_result = run_test(methods, q, k, v)
    if triton.knobs.runtime.interpret or torch.cuda.is_available():
        device = "cpu" if triton.knobs.runtime.interpret else "cuda"
        q_gpu, k_gpu, v_gpu = (t.to(device=device, dtype=torch.float16) for t in (q, k, v))
        for causal in (False, True):
            scores = q_gpu.float() @ k_gpu.float().T * head_dim ** -0.5
            if causal:
                mask = torch.arange(seq_len, device=q_gpu.device)
                scores = scores.masked_fill(mask[:, None] < mask[None, :], -float("inf"))
            ref = torch.softmax(scores, dim=-1) @ v_gpu.float()
            out = fa_v2_tl(q_gpu, k_gpu, v_gpu, causal=causal)
            torch.testing.assert_close(out.float(), ref, atol=2e-3, rtol=2e-3)
            print(f"fa_v2_tl causal={causal} | max_diff = {(out.float() - ref).abs().max().item():.3e}")
