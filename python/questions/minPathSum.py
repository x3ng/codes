from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        gr = len(grid)
        gc = len(grid[0])
        rl = [10**18] * gc
        rl[0] = 0
        for r in range(gr):
            rl[0] += grid[r][0]
            for c in range(1, gc):
                rl[c] = min(rl[c], rl[c-1]) + grid[r][c]
        return rl[-1]
