from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        if nums[r] > nums[l]:
            return nums[l]
        while l < r:
            m = (l + r) // 2
            if nums[m] >= nums[l]:
                if nums[r] < nums[l]:
                    l = m + 1
                else:
                    return nums[l]
            else:
                r = m
        return nums[l]
