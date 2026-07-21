class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        r = [1] * n
        for _ in range(m-1):
            for j in range(1, n):
                r[j] += r[j-1] 
        return r[-1]
