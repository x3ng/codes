from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ln = len(nums)
        dp = [nums[0]] * 2
        ans = nums[0]
        for i in range(1, ln):
            n = nums[i]
            l, h = dp
            dp[0] = min(l*n, h*n, n) 
            dp[1] = max(l*n, h*n, n)
            ans = max(ans, dp[1])
        return ans
