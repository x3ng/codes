from typing import List

class Solution:
    ds = [[0, 1], [1, 0], [0, -1], [-1, 0]]

    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0]*n for _ in range(n)]
        d = 0
        r = 0
        c = 0
        for p in range(1, n*n+1):
            ans[r][c] = p
            nr = r + self.ds[d][0]
            nc = c + self.ds[d][1]
            if nr<0 or nc>=n or nr>=n or nc<0 or ans[nr][nc]:
                d = (d + 1) % 4
                r += self.ds[d][0]
                c += self.ds[d][1]
            else:
                r = nr
                c = nc
        return ans
