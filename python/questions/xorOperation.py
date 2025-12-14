class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        xor_n = lambda n: (n, 1, n+1, 0)[n%4]
        a = start // 2
        b = n & start & 1
        return (xor_n(a+n-1)^xor_n(a-1))*2+b
