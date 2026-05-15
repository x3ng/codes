class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        l = 0
        r = 0
        ext = set()
        while r < len(s):
            if s[r] in ext:
                ans = max(ans, r-l)
                while s[r] in ext:
                    ext.remove(s[l])
                    l += 1
            ext.add(s[r])
            r += 1
        ans = max(ans, r-l)
        return ans
