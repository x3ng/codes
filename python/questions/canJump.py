from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        f = 0
        ln = len(nums)
        for i in range(ln):
            if i <= f:
                f = max(f, i+nums[i])
                if f >= ln-1:
                    return True
        return False
