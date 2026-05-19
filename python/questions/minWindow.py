class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ss = -1
        ml = len(s) + 1
        cc = [0] * 128
        df = 0
        for c in t:
            if cc[ord(c)] == 0:
                df += 1
            cc[ord(c)] -= 1
        l = 0
        for r in range(len(s)):
            cc[ord(s[r])] += 1
            if (cc[ord(s[r])] == 0):
                df -= 1
            if df == 0:
                while cc[ord(s[l])] != 0:
                    cc[ord(s[l])] -= 1
                    l += 1
                if r-l+1 < ml:
                    ss = l
                    ml = r-l+1
                cc[ord(s[l])] -= 1
                df += 1
                l += 1
        return s[ss:ss+ml] if ss!=-1 else ""
