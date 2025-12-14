import typing
import torch
import torch.nn as nn

class crossAttention(nn.Module):
    def __init__(self, embed_dim: int, num_heads: int, dropout: int=0.1):
        super(crossAttention, self).__init__()
        assert embed_dim%num_heads == 0, f'embed_dim {embed_dim}, num_heads {num_heads} no suited'
        self.embed_dim = embed_dim
        self.num_heads = num_heads
        self.dropout = dropout
        self.head_dim = embed_dim // num_heads
        self.scale = self.head_dim ** -0.5

        self.q_proj = nn.Linear(embed_dim, embed_dim)
        self.k_proj = nn.Linear(embed_dim, embed_dim)
        self.v_proj = nn.Linear(embed_dim, embed_dim)
        self.out_proj = nn.Linear(embed_dim, embed_dim)

        self.attn_drop = nn.Dropout(dropout)
        self.out_drop = nn.Dropout(dropout)

    def forward(self, q: torch.Tensor, k: torch.Tensor, v: torch.Tensor, mask: torch.Tensor=None) -> torch.Tensor:
        b, tgt_n, d = q.shape
        src_n = k.shape[1]

        q = self.q_proj(q).reshape(b, tgt_n, self.num_heads, self.head_dim).permute(0, 2, 1, 3)
        k = self.k_proj(k).reshape(b, src_n, self.num_heads, self.head_dim).permute(0, 2, 3, 1)
        v = self.v_proj(v).reshape(b, src_n, self.num_heads, self.head_dim).permute(0, 2, 1, 3)

        attn_scores = (q @ k) * self.scale

        if mask is not None:
            if mask.dtype == bool:
                mask = mask.masked_fill(mask, -float('inf'))
            attn_scores = attn_scores + mask

        attn_probs = attn_scores.softmax(dim=-1)
        attn_probs = self.attn_drop(attn_probs)

        out = attn_probs @ v
        out = out.transpose(1, 2).reshape(b, tgt_n, d)
        out = self.out_proj(out)
        out = self.out_drop(out)

        return out

if __name__ == "__main__":
    batch, tgt_len, embed_dim = 2, 5, 768
    batch, src_len, embed_dim = 2, 7, 768
    num_heads = 6

    de_tk = torch.randn(batch, tgt_len, embed_dim)
    en_tk = torch.randn(batch, src_len, embed_dim)

    model = crossAttention(embed_dim, num_heads)

    out = model(de_tk, en_tk, en_tk)

    print(f'q {de_tk.shape}, kv {en_tk.shape}, out {out.shape}')
    
