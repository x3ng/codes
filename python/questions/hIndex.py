from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        lc = len(citations)
        rc = [0] * (lc + 1)
        for c in citations:
            if c >= lc:
                rc[lc] += 1
            else:
                rc[c] += 1
        rs = 0
        for p in range(lc, -1, -1):
            rs += rc[p]
            if rs >= p:
                return p
        return 0
