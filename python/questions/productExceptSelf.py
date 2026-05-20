from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n 
        pp = 1
        for i in range(n):
            ans[i] = pp
            pp *= nums[i]
        pp = 1
        for i in range(n-1, -1, -1):
            ans[i] *= pp
            pp *= nums[i]
        return ans
