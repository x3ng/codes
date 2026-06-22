from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        tmp = ['0'] * n * 2
        def bs(p: int, l: int) -> None:
            if l == n:
                while p < n*2:
                    tmp[p] = ')'
                    p += 1
                ans.append("".join(tmp))
                return
            if p < l*2:
                tmp[p] = ')'
                bs(p+1, l)
            tmp[p] = '('
            bs(p+1, l+1)
        bs(0, 0)
        return ans
