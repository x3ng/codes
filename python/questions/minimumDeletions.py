class Solution:
    def minimumDeletions(self, s: str) -> int:
        de = 0
        for c in s:
            de += ord('b') - ord(c)
        ans = de
        for c in s:
            de += (ord(c)-ord('a'))*2 - 1;
            ans = min(ans, de)
        return ans
