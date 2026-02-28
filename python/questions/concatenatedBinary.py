class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 1000000007
        ans = 0
        for cn in range(1, n+1):
            cnc = cn.bit_length()
            ans = ((ans << cnc) | cn) % MOD
        return ans
