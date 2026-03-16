import torch

token_num = 3
embed_dim = 4

softmax_scal = torch.sqrt(torch.tensor(embed_dim, dtype=torch.float32))

br = 2
bc = 2

q = torch.randn(token_num, embed_dim)
k = torch.randn(token_num, embed_dim)
v = torch.randn(token_num, embed_dim)

o = torch.zeros(token_num, embed_dim)

m = torch.tensor([-float("inf")] * token_num).reshape(token_num, 1)
l = torch.zeros(token_num, 1)

for cc in range((token_num+bc-1)//bc):
    ck = k[cc*bc:min((cc+1)*bc, token_num), :]
    cv = v[cc*bc:min((cc+1)*bc, token_num), :]
    for cr in range((token_num+br-1)//br):
        po = o[cr*br:min((cr+1)*br, token_num), :]
        pm = m[cr*br:min((cr+1)*br, token_num), :]
        pl = l[cr*br:min((cr+1)*br, token_num), :]
        cq = q[cr*br:min((cr+1)*br, token_num), :]

        cs = torch.matmul(cq, ck.transpose(-2, -1)) / softmax_scal
        cm, _ = torch.max(cs, dim=1, keepdim=True)
        cm, _ = torch.max(torch.cat([pm, cm], dim=1), dim=1, keepdim=True)
        cse = torch.exp(cs - cm)

        cl = torch.sum(cse, dim=1, keepdim=True)
        cl += torch.exp(pm - cm) * pl
        
        co = torch.matmul(cse, cv)

        o[cr*br:min((cr+1)*br, token_num), :] = (torch.exp(pm - cm) * pl * po + co) / cl
        m[cr*br:min((cr+1)*br, token_num), :] = cm
        l[cr*br:min((cr+1)*br, token_num), :] = cl

pytorch_o = torch.matmul(torch.softmax(torch.matmul(q, k.transpose(-2, -1)) / softmax_scal, dim=-1), v)

print("---------- flash attention ----------")
print(o)
print("---------- pytorch attention ----------")
print(pytorch_o)
print("---------- difference ----------")
print(o-pytorch_o)
