class Solution:
    def myPow(self, x: float, n: int) -> float:
        pn = n
        if n < 0:
            x = 1 / x
            pn = -pn
        ans = 1
        while pn > 0:
            ans *= x if pn&1 else 1
            x *= x
            pn >>= 1
        return ans
