from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxs = nums[0]
        curs = 0
        for n in nums:
            curs = n if curs < 0 else curs + n
            if curs > maxs:
                maxs = curs
        return maxs
