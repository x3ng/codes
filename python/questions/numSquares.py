import math

class Solution:
    def numSquares(self, n: int) -> int:
        dp = [n] * (n+1)
        dp[0] = 0
        for i in range(1, math.isqrt(n)+1):
            c2 = i * i
            for j in range(c2, n+1):
                dp[j] = min(dp[j], dp[j-c2]+1)
        return dp[-1]
