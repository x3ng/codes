from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        zp = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[zp], nums[i] = nums[i], nums[zp]
                zp += 1
