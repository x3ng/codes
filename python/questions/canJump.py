from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        ln = len(nums)
        ms = 0
        i = 0
        while i <= ms:
            ms = max(ms, i + nums[i])
            i += 1
            if ms >= ln - 1:
                return True
        return False
