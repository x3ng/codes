from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # r = len(nums) - 1
        # l = 0
        # ans = [0] * len(nums)
        # for p in range(len(nums)-1, -1, -1):
        #     if nums[r] > -nums[l]:
        #         ans[p] = nums[r] * nums[r]
        #         r -= 1
        #     else:
        #         ans[p] = nums[l] * nums[l]
        #         l += 1
        # return ans
        return sorted([num**2 for num in nums])
