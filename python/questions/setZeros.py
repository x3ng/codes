from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rs = len(matrix)
        cs = len(matrix[0])
        r00 = False
        for c in range(cs):
            if matrix[0][c] == 0:
                r00 = True
        for r in range(1, rs):
            r0 = False
            for c in range(cs):
                if matrix[r][c] == 0:
                    matrix[0][c] = 0
                    r0 = True
            if r0:
                for c in range(cs):
                    matrix[r][c] = 0
        for c in range(cs):
            if matrix[0][c] == 0:
                for r in range(1, rs):
                    matrix[r][c] = 0
        if r00:
            for c in range(cs):
                matrix[0][c] = 0
