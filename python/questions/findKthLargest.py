from typing import List
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        hq = []
        for n in nums:
            if len(hq) < k:
                heapq.heappush(hq, n)
            elif n > hq[0]:
                heapq.heappop(hq)
                heapq.heappush(hq, n)
        return hq[0]
