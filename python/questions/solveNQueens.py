from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        tmp = [['.' for _ in range(n)] for _ in range(n)]
        cp = [False] * n
        ml = [False] * (2 * n - 1)
        pl = [False] * (2 * n - 1)
        def bt(r: int) -> None:
            if r == n:
                ans.append(["".join(rv) for rv in tmp])
                return
            for c in range(n):
                if not cp[c] and not ml[r-c+n-1] and not pl[r+c]:
                    tmp[r][c] = 'Q'
                    cp[c] = True
                    ml[r-c+n-1] = True
                    pl[r+c] = True
                    bt(r+1)
                    tmp[r][c] = '.'
                    cp[c] = False
                    ml[r-c+n-1] = False
                    pl[r+c] = False
        bt(0)
        return ans
