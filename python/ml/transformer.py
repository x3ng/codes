import torch
from torch import nn


class MHSA(nn.Module):
    def __init__(self, embed_dim, num_heads, drop_out=0.1):
        super(MHSA, self).__init__()
        self.qkv = nn.Linear(in_features=embed_dim, out_features=3*embed_dim)
        self.dropout = nn.Dropout(drop_out)
        self.out = nn.Linear(in_features=embed_dim, out_features=embed_dim)

        self.embed_dim = embed_dim
        self.num_heads = num_heads
        self.head_dim = embed_dim // num_heads
        self.scale = self.head_dim ** 0.5
        

    def forward(self, x):
        b, n, d = x.shape
        qkv = self.qkv(x).reshape(b, n, 3, self.num_heads, self.head_dim).permute(2, 0, 3, 1, 4)
        q, k, v = qkv[0], qkv[1], qkv[2]
        attn_scores = (q @ k.transpose(-2, -1)) / self.scale
        attn_probe = attn_scores.softmax(dim=-1)
        out = attn_probe @ v
        out = out.transpose(1, 2).reshape(b, n, self.embed_dim)
        out = self.out(out)
        return out


class MLP(nn.Module):
    def __init__(self, embed_dim, hidden_dim):
        super(MLP, self).__init__()
        self.lin1 = nn.Linear(in_features=embed_dim, out_features=hidden_dim)
        self.act1 = nn.GELU()
        self.lin2 = nn.Linear(in_features=hidden_dim, out_features=embed_dim)

    def forward(self, x):
        x = self.lin1(x)
        x = self.act1(x)
        x = self.lin2(x)
        return x


class transformer(nn.Module):
    def __init__(self, embed_dim, num_heads, hidden_dim, drop_out=0.1):
        super(transformer, self).__init__()
        self.attn = MHSA(embed_dim, num_heads)
        self.mlp = MLP(embed_dim, hidden_dim)

    def forward(self, x):
        res = x
        x = self.attn(x) + res
        res = x
        x = self.mlp(x) + res
        return x


if __name__ == "__main__":
    model = transformer(768, 12, 2*768)
    from torchsummary import summary
    print(summary(model, (197, 768)))
    
