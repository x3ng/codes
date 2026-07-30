from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        r = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[r] = nums[i]
                r += 1
        return r
