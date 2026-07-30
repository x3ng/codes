from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ln = len(nums)
        vp = 0
        for n in nums:
            if n != nums[vp]:
                vp += 1
                nums[vp] = n
        return vp + 1
