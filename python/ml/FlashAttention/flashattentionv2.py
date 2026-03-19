# flash attention v2

import torch

batch_size = 2
token_num = 5
embed_dim = 6

softmax_scale = torch.sqrt(torch.tensor(embed_dim, dtype=torch.float32))

br = 2
bc = 2

q = torch.randn(batch_size, token_num, embed_dim)
k = torch.randn(batch_size, token_num, embed_dim)
v = torch.randn(batch_size, token_num, embed_dim)

m = torch.tensor([[-float("inf") for _ in range(token_num)] for _ in range(batch_size)]).reshape(batch_size, token_num, 1)
l = torch.zeros(batch_size, token_num, 1)
o = torch.zeros(batch_size, token_num, embed_dim)

for cr in range(0, (token_num+br-1)//br):
    cq = q[:, cr*br:min(token_num, (cr+1)*br), :]
    co = o[:, cr*br:min(token_num, (cr+1)*br), :]
    cm = m[:, cr*br:min(token_num, (cr+1)*br), :]
    cl = l[:, cr*br:min(token_num, (cr+1)*br), :]
    for cc in range(0, (token_num+bc-1)//bc):
        pm = cm
        pl = cl
        ck = k[:, cc*bc:min(token_num, (cc+1)*bc), :]
        cv = v[:, cc*bc:min(token_num, (cc+1)*bc), :]

        cs = cq @ ck.transpose(-1, -2) / softmax_scale
        ccm, _ = torch.max(cs, dim=-1, keepdim=True)
        cm, _ = torch.max(torch.cat([pm, ccm], dim=-1), dim=-1, keepdim=True)

        co = (torch.exp(cs - cm)) @ cv + (torch.exp(pm - cm)) * co
        cl = torch.sum(torch.exp(cs - cm), dim=-1, keepdim=True) + (torch.exp(pm - cm)) * pl
    o[:, cr*br:min(token_num, (cr+1)*br), :] = co / cl
    m[:, cr*br:min(token_num, (cr+1)*br), :] = cm
    l[:, cr*br:min(token_num, (cr+1)*br), :] = cl

print("----- flash attention v2 -----")
print(o)
print("----- pytorch softmax ----")
ps = torch.softmax(q @ k.transpose(-1, -2) / softmax_scale, dim=-1) @ v
print(ps)
print("----- diff -----")
print(o-ps)
