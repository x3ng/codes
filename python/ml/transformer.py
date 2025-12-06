import torch
from torch import nn


class MHSA (nn.Module):
    def __init__(self, embed_dim: int, num_heads: int, dropout: float = 0.1):
        super(MHSA, self).__init__()
        
        assert embed_dim % num_heads == 0, f"embed_dim{embed_dim}%numheads{num_heads}!=0"
        
        self.qkv = nn.Linear(in_features=embed_dim, out_features=3*embed_dim)
        self.attn_dropout = nn.Dropout(dropout)
        self.out = nn.Linear(in_features=embed_dim, out_features=embed_dim)
        self.out_dropout = nn.Dropout(dropout)

        self.embed_dim = embed_dim
        self.num_heads = num_heads
        self.head_dim = embed_dim // num_heads
        self.scale = self.head_dim ** 0.5
        

    def forward(self, x):
        b, n, d = x.shape
        assert d == self.embed_dim, f"input dim: {d} != embed_dim: {self.embed_dim}"
        qkv = self.qkv(x).reshape(b, n, 3, self.num_heads, self.head_dim).permute(2, 0, 3, 1, 4)
        q, k, v = qkv[0], qkv[1], qkv[2]
        attn_scores = (q @ k.transpose(-2, -1)) / self.scale
        attn_probs = attn_scores.softmax(dim=-1)
        attn_probs = self.attn_dropout(attn_probs)
        out = attn_probs @ v
        out = out.transpose(1, 2).reshape(b, n, self.embed_dim)
        out = self.out(out)
        out = self.out_dropout(out)
        return out


class MLP(nn.Module):
    def __init__(self, embed_dim: int, hidden_dim: int, dropout: float = 0.1):
        super(MLP, self).__init__()
        self.lin1 = nn.Linear(in_features=embed_dim, out_features=hidden_dim)
        self.act1 = nn.GELU()
        self.lin2 = nn.Linear(in_features=hidden_dim, out_features=embed_dim)
        self.dropout = nn.Dropout(dropout)

    def forward(self, x):
        x = self.lin1(x)
        x = self.act1(x)
        x = self.lin2(x)
        x = self.dropout(x)
        return x


class TransformerBlock(nn.Module):
    def __init__(self, embed_dim: int, num_heads: int, hidden_dim: int, dropout: float = 0.1):
        super(TransformerBlock, self).__init__()
        self.norm1 = nn.LayerNorm(embed_dim, eps=1e-6)
        self.attn = MHSA(embed_dim, num_heads, dropout)
        self.norm2 = nn.LayerNorm(embed_dim, eps=1e-6)
        self.mlp = MLP(embed_dim, hidden_dim, dropout)

    def forward(self, x):
        res = x
        x = self.attn(self.norm1(x)) + res
        res = x
        x = self.mlp(self.norm2(x)) + res
        return x


if __name__ == "__main__":
    model = TransformerBlock(768, 12, 2*768)
    from torchsummary import summary
    print(summary(model, (197, 768)))
    
