class Solution:
    def hammingWeight(self, n: int) -> int:
        bn = bin(n)[2:]
        return bn.count('1')
