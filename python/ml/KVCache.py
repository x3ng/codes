import typing
import torch

from maskMHSA import maskMHSA

class KVCache:
    def __init__(self, max_seq_len: int, embed_dim: int, num_heads: int, device: torch.device):
        self.max_seq_len = max_seq_len
        self.num_heads = num_heads
        self.head_dim = embed_dim // num_heads
        self.device = device

        #self.k_cache = torch.zeros((0, num_heads, 0, self.head_dim)).to(device)
        #self.v_cache = torch.zeros((0, num_heads, 0, self.head_dim)).to(device)
        self.k_cache = None
        self.v_cache = None

    def update(self, k: torch.Tensor, v: torch.Tensor) -> tuple[torch.Tensor, torch.Tensor]:
        assert k.shape==v.shape, f'k {k.shape}, v {v.shape} not equal'
        
        b = k.shape[0]
        if self.k_cache is None or self.v_cache is None:
            self.k_cache = k
            self.v_cache = v
        else:
            self.k_cache = torch.cat([self.k_cache, k], dim=-2)
            self.v_cache = torch.cat([self.v_cache, v], dim=-2)

        if self.k_cache.shape[-2] > self.max_seq_len:
            self.k_cache = self.k_cache[..., :self.max_seq_len, :]
        if self.v_cache.shape[-2] > self.max_seq_len:
            self.v_cache = self.v_cache[..., :self.max_seq_len, :]

        return self.k_cache, self.v_cache

    def reset(self):
        self.k_cache = torch.zeros((0, self.num_heads, 0, self.head_dim)).to(self.device)
        self.v_cache = torch.zeros((0, self.num_heads, 0, self.head_dim)).to(self.device)

class KVCacheMHSA(maskMHSA):
    def forward_with_cache(self, x: torch.Tensor, kv_cache: KVCache, attn_mask) -> tuple[torch.Tensor, KVCache]:
        b, n, d = x.shape
        assert n == 1, "when inference, input is set as 1"
        qkv = self.qkv_proj(x).reshape(b, n, 3, self.num_heads, self.head_dim).permute(2, 0, 3, 1, 4)
        q, k, v = qkv[0], qkv[1], qkv[2]

        k_cache, v_cache = kv_cache.update(k, v)

        attn_scores = (q @ k_cache.transpose(-1, -2)) * self.scale

        if attn_mask is not None:
            if attn_mask.dtype == bool:
                attn_mask = attn_mask.masked_fill(attn_mask, -float('inf'))
            attn_scores = attn_scores + attn_mask

        attn_probs = attn_scores.softmax(dim=-1)
        attn_probs = self.attn_drop(attn_probs)

        out = attn_probs @ v_cache
        out = out.transpose(1, 2).reshape(b, n, d)
        out = self.out_proj(out)
        out = self.out_drop(out)

        return out, kv_cache

if __name__ == "__main__":
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    batch_size, embed_dim, num_heads = 2, 768, 12

    max_seq_len = 20

    kv_cache = KVCache(max_seq_len, embed_dim, num_heads, device)

    model = KVCacheMHSA(embed_dim, num_heads).to(device)

    for i in range(5):
        x = torch.randn(batch_size, 1, embed_dim).to(device)
        mask = torch.tril(torch.ones(1, 1, i+1)).to(device) == 0
        out, kv_cache = model.forward_with_cache(x, kv_cache, attn_mask=mask)
        print(f'token {i}, out {out.shape}, kv_cache {kv_cache.k_cache.shape}')
    kv_cache.reset()
        
