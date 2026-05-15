from collections import defaultdict
from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        dt = defaultdict(int)
        ps = 0
        dt[ps] += 1
        for n in nums:
            ps += n
            ans += dt[ps-k]
            dt[ps] += 1
        return ans
