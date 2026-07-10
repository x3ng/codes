from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        ans.append([1])
        for i in range(1, numRows):
            pr = ans[i-1]
            cr = [1] * (i+1)
            for j in range(1, i):
                cr[j] = pr[j] + pr[j-1]
            ans.append(cr)
        return ans
