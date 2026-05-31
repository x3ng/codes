from typing import List

class Solution:
    DIR = [[0, 1], [1, 0], [0, -1], [-1, 0]]

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rs = len(matrix)
        cs = len(matrix[0])
        ans = [0] * rs * cs
        d = 0
        r = 0
        c = 0
        oc = 0
        l = 0
        while oc < rs*cs:
            ans[oc] = matrix[r][c]
            oc += 1
            match d:
                case 0:
                    if c == cs-1-l:
                        d = 1
                case 1:
                    if r == rs-1-l:
                        d = 2
                case 2:
                    if c == l:
                        d = 3
                case 3:
                    if r == l+1:
                        l += 1
                        d = 0
            r += self.DIR[d][0]
            c += self.DIR[d][1]
        return ans
