from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mp = 0
        for i in range(1, len(prices)):
            cp = prices[i] - prices[i - 1]
            mp += cp if cp > 0 else 0
        return mp
