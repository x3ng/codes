from typing import List
from collections import defaultdict
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dt = defaultdict(int)
        for n in nums:
            dt[n] += 1
        hq = []
        for n, c in dt.items():
            if len(hq) < k:
                heapq.heappush(hq, (c, n))
            elif c > hq[0][0]:
                heapq.heappop(hq)
                heapq.heappush(hq, (c, n))
        return [n for _, n in hq]
            
