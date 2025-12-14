import typing
import torch
import torch.nn as nn

class maskMHSA(nn.Module):
    def __init__(self, embed_dim: int, num_heads: int, dropout: float=0.1):
        super().__init__()
        assert embed_dim % num_heads == 0, f'error embed_dim {embed_dim} could not device num_heads {num_heads}'
        self.embed_dim = embed_dim
        self.num_heads = num_heads
        self.dropout = dropout
        self.head_dim = embed_dim // num_heads
        self.scale = self.head_dim ** -0.5

        self.qkv_proj = nn.Linear(embed_dim, 3*embed_dim)
        self.out_proj = nn.Linear(embed_dim, embed_dim)

        self.attn_drop = nn.Dropout(dropout)
        self.out_drop = nn.Dropout(dropout)

    def forward(self, x: torch.Tensor, attn_mask: torch.Tensor=None) -> torch.Tensor:
        B, N, D = x.shape
        assert D == self.embed_dim, f'input dim {D} not equal to embed_dim {self.embed_dim}'
        qkv = self.qkv_proj(x).reshape(B, N, 3, self.num_heads, self.head_dim).permute(2, 0, 3, 1, 4)
        q, k, v = qkv[0], qkv[1], qkv[2]

        attn_score = (q @ k.transpose(-1, -2)) * self.scale

        if attn_mask is not None:
            if attn_mask.dtype == torch.bool:
                attn_mask = attn_mask.masked_fill(attn_mask, -float('inf'))
            attn_score = attn_score + attn_mask

        attn_probs = attn_score.softmax(dim=-1)
        attn_probs = self.attn_drop(attn_probs)

        out = attn_probs @ v
        out = out.transpose(1, 2).reshape(B, N, D)
        out = self.out_proj(out)
        out = self.out_drop(out)

        return out

if __name__ == "__main__":
    batch, seqlen, embedim = 2, 5, 768
    num_heads = 12
    x = torch.rand((batch, seqlen, embedim))
    mask = torch.tril(torch.ones(seqlen, seqlen)).unsqueeze(0).unsqueeze(0)
    mask = mask == 0

    model = maskMHSA(embedim, num_heads)
    out = model(x, mask)
    print(f"origin {x.shape}, out {out.shape}")
