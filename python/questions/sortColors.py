from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        ln = len(nums)
        l = 0
        r = ln - 1
        p = l
        while p <= r:
            if nums[p] == 0:
                nums[l], nums[p] = nums[p], nums[l]
                while l<ln and nums[l]==0:
                    l += 1
                p = max(l, p)
            elif nums[p] == 2:
                nums[r], nums[p] = nums[p], nums[r]
                while r>=0 and nums[r]==2:
                    r -= 1
            p += 1 if p<ln and nums[p]==1 else 0
