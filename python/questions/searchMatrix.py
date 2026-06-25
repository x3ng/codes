from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        lr = len(matrix)
        lc = len(matrix[0])
        s = 0
        e = lr
        while s < e:
            m = (s + e) // 2
            cv = matrix[m][lc-1]
            if cv == target:
                return True
            elif cv > target:
                e = m
            else:
                s = m + 1
        if s >= lr or target < matrix[s][0]:
            return False
        r = s
        s = 0
        e = lc
        while s < e:
            m = (s + e) // 2
            cv = matrix[r][m]
            if cv == target:
                return True
            elif cv > target:
                e = m
            else:
                s = m + 1
        return matrix[r][s] == target
