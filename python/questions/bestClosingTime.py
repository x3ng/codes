class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        ans = -1
        minc = 0
        yc = 0
        nc = 0
        for p in range(n):
            if customers[p] == 'N':
                nc += 1
            else:
                yc -= 1
            if minc > nc+yc:
                minc = nc+yc
                ans = p
        if ans == -1:
            return 0
        else:
            return ans + 1
