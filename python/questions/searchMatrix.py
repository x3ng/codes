from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rs = len(matrix)
        r = 0
        c = len(matrix[0]) - 1
        while True:
            if r>=rs or c<0:
                return False
            elif matrix[r][c] == target:
                return True
            elif matrix[r][c] > target:
                c -= 1
            elif matrix[r][c] < target:
                r += 1
