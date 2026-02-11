class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        cl = len(grid)
        rl = len(grid[0])
        ans = 0
        def marklands(c: int, r: int):
            grid[c][r] = '2'
            if c > 0 and grid[c-1][r] == '1':
                marklands(c-1, r)
            if c < cl-1 and grid[c+1][r] == '1':
                marklands(c+1, r)
            if r > 0 and grid[c][r-1] == '1':
                marklands(c, r-1)
            if r < rl-1 and grid[c][r+1] == '1':
                marklands(c, r+1)
        for cp in range(cl):
            for rp in range(rl):
                if grid[cp][rp] == '1':
                    marklands(cp, rp)
                    ans += 1
        return ans
