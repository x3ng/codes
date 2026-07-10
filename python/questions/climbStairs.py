class Solution:
    def climbStairs(self, n: int) -> int:
        cc = [-1] * (n+1)
        def cs(n: int) -> int:
            nonlocal cc
            if cc[n] != -1:
                return cc[n]
            if n <= 1:
                cc[n] = 1
            else:
                cc[n] = cs(n-1) + cs(n-2)
            return cc[n]
        return cs(n)
