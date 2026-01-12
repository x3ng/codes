class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        ans = 0
        px, py = points[0]
        for p in range(1, len(points)):
            cx, cy = points[p]
            ans += max(abs(cx-px), abs(cy-py))
            px, py = cx, cy
        return ans
