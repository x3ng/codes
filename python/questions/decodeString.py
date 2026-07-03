class Solution:
    def decodeString(self, s: str) -> str:
        ans = ""
        p = 0
        while p < len(s):
            oc = ord(s[p])
            if oc>=ord('a') and oc<=ord('z'):
                ans += s[p]
                p += 1
            else:
                rt = 0
                while s[p] != '[':
                    rt *= 10
                    rt += int(s[p])
                    p += 1
                lmr = 1
                sp = p + 1
                while lmr:
                    p += 1
                    if s[p] == '[':
                        lmr += 1
                    elif s[p] == ']':
                        lmr -= 1
                ss = self.decodeString(s[sp:p])
                ans += ss * rt
                p += 1
        return ans
