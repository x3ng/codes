from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        lr = len(matrix)
        lc = len(matrix[0])
        r = 0
        c = lc - 1
        while r<lr and c>=0:
            if matrix[r][c] == target:
                return True
            elif matrix[r][c] > target:
                c -= 1;
            else:
                r += 1;
        return False
