from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nz = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[nz] = nums[i]
                nz += 1
        for i in range(nz, len(nums)):
            nums[i] = 0
