from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        ans = 0
        h = 0
        w = 0
        while l < r:
            w = r - l
            if height[r] > height[l]:
                h = height[l]
                l += 1
            else:
                h = height[r]
                r -= 1
            ans = max(ans, h*w)
        return ans

