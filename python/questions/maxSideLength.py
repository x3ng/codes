class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m = len(mat)
        n = len(mat[0])
        maxSide = 0
        prew = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                prew[i+1][j+1] = prew[i+1][j] + prew[i][j+1] - prew[i][j] + mat[i][j]
                if i>=maxSide and j>=maxSide:
                    cs = prew[i+1][j+1] - prew[i+1][j-maxSide] - prew[i-maxSide][j+1] + prew[i-maxSide][j-maxSide]
                    if cs <= threshold:
                        maxSide += 1
        return maxSide
