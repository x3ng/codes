from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        r = len(nums) - 1
        if r < 0:
            return 0
        l = 0
        while l < r:
            if nums[l] == val:
                while r>l and nums[r]==val:
                    r -= 1
                nums[l], nums[r] = nums[r], nums[l]
            l += 1
        return r if nums[r]==val else r+1
