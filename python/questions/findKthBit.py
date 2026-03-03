class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n == 1:
            return '0'
        m = 1 << (n - 1)
        if k == m:
            return '1'
        elif k < m:
            return self.findKthBit(n-1, k)
        else:
            return '1' if self.findKthBit(n-1, (m<<1)-k) == '0' else '0'
