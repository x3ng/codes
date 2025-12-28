class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        rd = len(grid)-1
        cr = len(grid[0])-1
        ru = 0
        cl = cr
        ans = 0
        while ru<=rd and grid[ru][cr]>=0:
            ru += 1
        while ru<=rd and grid[rd][0]<0:
            rd -= 1
            ans += cr+1
        while ru <= rd:
            while cl>=0 and grid[ru][cl]<0:
                cl -= 1
            ans += cr - cl
            ru += 1
        return ans
            
