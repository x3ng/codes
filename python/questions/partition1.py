from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ls = len(s)
        ans = []
        tmp = []
        def ir(l: int, r: int) -> bool:
            nonlocal s
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True
        def bs(p: int) -> None:
            if p == ls:
                ans.append(tmp.copy())
                return
            l = p
            for r in range(l, ls):
                if ir(l, r):
                    tmp.append(s[l:r+1])
                    bs(r+1)
                    tmp.pop()
        bs(0)
        return ans
