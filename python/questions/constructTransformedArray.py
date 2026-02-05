from typing import List

class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        return [nums[(n+(p+nums[p]%n))%n] for p in range(n)]
