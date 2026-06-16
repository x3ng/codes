from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rl = len(grid)
        cl = len(grid[0])
        def step(r: int, c: int) -> None:
            nonlocal rl, cl
            if r<0 or r>=rl or c<0 or c>=cl or grid[r][c]=='0':
                return
            grid[r][c] = '0'
            step(r-1, c)
            step(r+1, c)
            step(r, c-1)
            step(r, c+1)
        ans = 0
        for i in range(rl):
            for j in range(cl):
                if grid[i][j] == '1':
                    ans += 1
                    step(i, j)
        return ans

