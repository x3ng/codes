class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        rs = len(grid)
        cs = len(grid[0])
        t0c = [ rs for _ in range(rs)]
        for r in range(rs):
            for c in range(cs-1, -1, -1):
                if grid[r][c]:
                    t0c[r] = cs - c -1
                    break;
        ans = 0
        for p in range(rs):
            for sp in range(p, rs):
                if t0c[sp] >= rs-p-1:
                    ans += sp - p
                    t0c[p+1:sp+1] = t0c[p:sp]
                    break
            else:
                return -1
        return ans
