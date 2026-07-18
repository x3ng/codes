from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        tn = sum(nums)
        if tn % 2:
            return False
        tn //= 2
        dp = [False for _ in range(tn+1)]
        dp[0] = True
        for n in nums:
            for i in range(len(dp)-1, -1, -1):
                pp = i - n
                if pp>=0 and dp[pp]:
                    dp[i] = True
            if dp[-1]:
                return True
        return False
