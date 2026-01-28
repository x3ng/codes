from typing import List

class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        r = len(grid)
        c = len(grid[0])
        maxn = -float('inf')
        for row in grid:
            maxn = max(maxn, max(row))
        gmj = [float('inf') for _ in range(maxn+2)]
        cmj = [float('inf') for _ in range(maxn+1)]
        for j in range(k+1):
            rowc = [float('inf') for _ in range(c+1)]
            rowc[1] = -grid[0][0]
            for ri in range(r):
                for ci in range(c):
                    cv = grid[ri][ci]
                    rowc[ci+1] = min(min(rowc[ci], rowc[ci+1])+cv, gmj[cv])
                    cmj[cv] = min(cmj[cv], rowc[ci+1])
            for n in range(maxn, -1, -1):
                gmj[n] = min(gmj[n+1], cmj[n])
        return rowc[-1]
