from typing import List
from collections import deque

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        nn = {}
        for s, e, c in zip(original, changed, cost):
            if s not in nn:
                nn[s] = {}
                nn[s][s] = 0
            nn[s][e] = min(nn[s].get(e, float('inf')), c)
        gdone = set()
        for s in nn:
            gdone.add(s)
            csc = nn[s]
            cl = deque(nn[s].keys())
            while cl:
                cll = len(cl)
                for _ in range(cll):
                    h = cl.popleft()
                    phd = nn.get(h, {})
                    for hd, cc in phd.items():
                        hdc = csc[h] + cc
                        if hdc < csc.get(hd, float('inf')):
                            csc[hd] = hdc
                            if h not in gdone:
                                cl.append(hd)
        ans = 0
        for p in range(len(source)):
            if source[p] != target[p]:
                csc = nn.get(source[p], None)
                if csc is None:
                    return -1
                cc = csc.get(target[p], float('inf'))
                if cc == float('inf'):
                    return -1
                ans += cc
        return ans
