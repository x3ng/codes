class Solution:
    def minOperations(self, s: str) -> int:
        ss = len(s)
        cnt = s[::2].count('0')
        cnt += s[1::2].count('1')
        return min(cnt, ss-cnt)
