from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        ans = [-1, -1]
        ln = len(nums)        
        if ln == 0:
            return ans
        l = 0
        r = ln
        while l < r:
            m = (l + r) // 2
            if nums[m] >= target:
                r = m
            else:
                l = m + 1
        if l >= ln or nums[l] != target:
            return ans
        ans[0] = l
        r = ln - 1
        while l < r:
            m = (l + r + 1) // 2
            if nums[m] <= target:
                l = m
            else:
                r = m - 1
        ans[1] = r
        return ans
