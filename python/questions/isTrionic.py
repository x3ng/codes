from typing import List

class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        p = 1
        while p<n and nums[p]>nums[p-1]:
            p += 1
        if p==1 or p==n:
            return False
        while p<n and nums[p]<nums[p-1]:
            p += 1
        if p==n:
            return False
        while p<n and nums[p]>nums[p-1]:
            p += 1
        return p==n
