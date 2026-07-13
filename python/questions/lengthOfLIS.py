from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        ln = len(nums)
        ans = 0
        ep = [0] * ln
        for n in nums:
            l = 0
            r = ans
            while l < r:
                m = (l + r) // 2
                if ep[m] >= n:
                    r = m
                else:
                    l = m + 1
            ep[l] = n
            ans = max(ans, l+1)
        return ans
