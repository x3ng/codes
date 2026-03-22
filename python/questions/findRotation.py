from typing import List

class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n = len(mat)
        flag = (1 << 4) - 1
        for r in range(n):
            for c in range(n):
                flag &= (
                    (mat[r][c] == target[r][c]) |
                    ((mat[r][c] == target[c][n-1-r]) << 1) |
                    ((mat[r][c] == target[n-1-r][n-1-c]) << 2) |
                    ((mat[r][c] == target[n-1-c][r]) << 3)
                )
                if not flag:
                    return False
        return bool(flag)
