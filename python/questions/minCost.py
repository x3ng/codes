from typing import List
import heapq

class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        sdc = [[] for _ in range(n)]
        for e in edges:
            s, d, w = e[0], e[1], e[2]
            sdc[s].append([w, d])
            sdc[d].append([w*2, s])
        dmw = [float('inf') for _ in range(n)]
        hq = []
        dmw[0] = 0
        heapq.heappush(hq, [0, 0])
        while len(hq):
            (cw, cs) = heapq.heappop(hq)
            if cw > dmw[cs]:
                continue
            if cs == n-1:
                return cw
            for e in sdc[cs]:
                nw = cw + e[0]
                if nw < dmw[e[1]]:
                    dmw[e[1]] = nw
                    heapq.heappush(hq, [nw, e[1]])
        return -1
