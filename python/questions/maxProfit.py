from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mv = prices[0]
        mp = 0
        for p in prices:
            mv = min(mv, p)
            mp = max(mp, p - mv)
        return mp
