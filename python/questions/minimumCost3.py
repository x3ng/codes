from typing import List
from sortedcontainers import SortedList

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        area = SortedList()
        curs = nums[0]
        for p in range(1, 2+dist):
            area.add(nums[p])
        curs += sum(area[:k-1]) 
        ans = curs
        for p in range(2+dist, len(nums)):
            ie = nums[p]
            de = nums[p-dist-1]
            area.add(nums[p])
            if ie <= area[k-2]:
                curs += ie - area[k-1]
            if de <= area[k-2]:
                curs += area[k-1] - de
            area.remove(de)
            ans = min(ans, curs)
        return ans
