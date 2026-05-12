from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dt = dict()
        for i in range(len(nums)):
            tmn = target - nums[i]
            cp = dt.get(tmn, -1)
            if cp != -1:
                return [i, cp]
            dt[nums[i]] = i
        return []
