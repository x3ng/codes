from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            m = (l + r) // 2
            if nums[m] == target:
                return m
            elif nums[m]<target:
                if nums[m]<nums[l] and nums[r]<target:
                    r = m - 1
                else:
                    l = m + 1
            elif nums[m]>target:
                if nums[m]>=nums[l] and nums[l]>target:
                    l = m + 1
                else:
                    r = m - 1
        return l if nums[l]==target else -1
