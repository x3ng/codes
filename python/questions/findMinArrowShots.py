from __future__ import annotations
import math

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        ans = 0
        pre = -math.inf
        for start, end in points:
            if start > pre:
                ans += 1
                pre = end
        return ans
        

if __name__ == "__main__":
    a = []
    a.append([1, 9])
    a.append([7, 8])
    a.append([3, 5])
    a.append([4, 6])
    b = Solution()
    print(b.findMinArrowShots(a))
