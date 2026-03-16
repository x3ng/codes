import torch

print(torch.__version__)

r, c = 3, 4

print("--- sofrmax --")

x = torch.randn(r, c)
e_x = torch.exp(x)
s_e_x = torch.sum(e_x, dim=1).unsqueeze(-1)

p = e_x / s_e_x

print(p)

print("-- safe softmax --")

x_r_m, _ = torch.max(x, dim=1)
x_r_m = x_r_m.unsqueeze(-1)

e_x_r_m = torch.exp(x_r_m)

s_e_x = e_x / e_x_r_m

s_s_e_x = torch.sum(s_e_x, dim=1).unsqueeze(-1)

s_p = s_e_x / s_s_e_x

print(s_p)
