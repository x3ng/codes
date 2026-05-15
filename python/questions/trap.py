from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        prem = height[l]
        sufm = height[r]
        ans = 0
        while l < r:
            if prem < sufm:
                ans += prem - height[l]
                l += 1
                prem = max(prem, height[l])
            else:
                ans += sufm - height[r]
                r -= 1
                sufm = max(sufm, height[r])
        return ans;
