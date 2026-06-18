from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ln = len(nums)
        ans = [[]]
        tmp = []
        def bs(p: int) -> None:
            tmp.append(nums[p])
            ans.append(tmp.copy())
            for i in range(p+1, ln):
                bs(i)
            tmp.pop()
        for i in range(ln):
            bs(i)
        return ans
