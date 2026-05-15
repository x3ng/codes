from typing import List
from collections import defaultdict

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        lp = len(p)
        ans = []
        l = 0
        r = 0
        dt = defaultdict(int)
        for c in p:
            dt[c] += 1
        while r < len(s):
            dt[s[r]] -= 1
            while dt[s[r]] < 0:
                dt[s[l]] += 1
                l += 1
            if r-l == lp-1:
                ans.append(l)
            r += 1
        return ans
