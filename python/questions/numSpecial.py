class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rs = len(mat)
        cs = len(mat[0])
        ans = 0
        colcnt = [sum(row[c] for row in mat)for c in range(cs)]
        for row in mat:
            if sum(row) != 1:
                continue
            cp = row.index(1)
            ans += colcnt[cp] == 1
        return ans
