from typing import List

class Solution:

    kc = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

    def letterCombinations(self, digits: str) -> List[str]:
        ld = len(digits)
        ans = []    
        tmp = ["0"] * ld
        def bs(p: int) -> None:
            if p == ld:
                ans.append("".join(tmp))
                return
            for c in self.kc[ord(digits[p])-ord('2')]:
                tmp[p] = c
                bs(p+1)
        bs(0)
        return ans
