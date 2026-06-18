from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ln = len(nums)
        ans = []
        fg = [False] * ln
        tmp = [0] * ln
        def bv(p: int) -> None:
            nonlocal tmp, fg, nums, ans, ln
            if p == ln:
                ans.append(tmp.copy())
            for i in range(ln):
                if not fg[i]:
                    tmp[p] = nums[i]
                    fg[i] = True
                    bv(p+1);
                    fg[i] = False
        bv(0)
        return ans
