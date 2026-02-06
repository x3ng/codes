from typing import List

class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        l = 0
        maxl = 0
        for r in range(0, len(nums)):
            while nums[l]*k < nums[r]:
                l += 1
            maxl = max(maxl, r-l+1)
        return len(nums) - maxl
