from typing import List

class Solution:
    DIR = [[0, 1], [1, 0], [0, -1], [-1, 0]]

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        cs = len(matrix[0])
        ns = len(matrix) - 1
        rp = 0
        cp = -1
        d = 0
        while (cs):
            for _ in range(cs):
                rp += self.DIR[d][0]
                cp += self.DIR[d][1]
                ans.append(matrix[rp][cp])
            cs, ns = ns, cs - 1
            d = (d + 1) % 4
        return ans
