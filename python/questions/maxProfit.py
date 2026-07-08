from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        pm = prices[0]
        ans = 0
        for p in prices:
            cp = p - pm
            ans = max(ans, cp)
            pm = min(p, pm)
        return ans
