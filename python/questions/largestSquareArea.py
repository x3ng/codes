class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        maxSide = 0
        n = len(bottomLeft)
        for i in range(n):
            if maxSide >= min(topRight[i][0]-bottomLeft[i][0], topRight[i][1]-bottomLeft[i][1]):
                continue
            for j in range(i+1, n):
                x = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0])
                y = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1])
                maxSide = max(maxSide, min(x, y))
        return maxSide * maxSide
