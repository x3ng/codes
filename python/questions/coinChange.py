from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount+1] * (amount+1)
        dp[0] = 0
        for c in coins:
            for cs in range(c, amount+1):
                dp[cs] = min(dp[cs], dp[cs-c] + 1)
        return -1 if dp[amount]==amount+1 else dp[amount]
