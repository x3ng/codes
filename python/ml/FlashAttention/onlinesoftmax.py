# 2-pass

import torch

r, c = 3, 4

x = torch.randn(r, c)
m = torch.tensor([-float('inf')] * r).reshape(r, 1)
d = torch.zeros(r, 1)

for p in range(c):
    tmp = m
    m = torch.max(m, x[:, p:p+1])
    e_m = torch.exp(-m)
    e_d = torch.exp(tmp - m)
    d = d * e_d + torch.exp(x[:, p:p+1]) * e_m

# print(f'{x.shape}, {m.shape}, {d.shape}')

p = torch.exp(x-m.reshape(r, 1)) / d.reshape(r, 1)

print(p)
