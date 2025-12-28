import typing
import torch
from torch import nn

class RoPE(nn.Module):
    def __init__(self, embed_dim: int):
        super().__init__()
        self.embed_dim = embed_dim
        assert embed_dim%2==0, f"{embed_dim} is not even"
        self.half_dim = self.embed_dim // 2
        self.register_buffer("theta", torch.Tensor([]), persistent=False)
        self.theta = 1.0 / (10000.0 ** (torch.arange(0, self.half_dim, dtype=torch.float32) * 2 / self.embed_dim))
        

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        b, n, d = x.shape
        assert d == self.embed_dim, f"embeddim{self.embed_dim}!=input_dim{d}"
        pos = torch.arange(n, device=x.device, dtype=torch.float32)[:, None]
        pos_theta = pos * self.theta
        cos_vals = torch.cos(pos_theta)[None, :, :]
        sin_vals = torch.sin(pos_theta)[None, :, :]
        x1, x2 =  x[..., ::2], x[..., 1::2]
        x1_rot = x1 * cos_vals - x2 * sin_vals
        x2_rot = x1 * sin_vals + x2 * cos_vals
        x_rot = torch.cat([x1_rot, x2_rot], dim=-1)
        return x_rot
        
if __name__ == "__main__":
# if 1:
    b, n, d = 2, 4, 6
    rope = RoPE(d)
    x = torch.rand((b, n, d))
    ropex = rope(x)
    print(x.shape, ropex.shape)
