class Solution:
    def longestPalindrome(self, s: str) -> str:
        ls = len(s)
        def ml(sp: int, ep: int) -> tuple[int, int]:
            while sp>=1 and ep<ls-1 and s[sp-1]==s[ep+1]:
                sp -= 1
                ep += 1
            return (sp, ep)
        ss = 0
        se = 0
        for i in range(ls):
            ns, ne = ml(i, i)
            if ne-ns > se-ss:
                ss = ns
                se = ne
            if i+1<ls and s[i]==s[i+1]:
                ns, ne = ml(i, i+1)
                if ne-ns > se-ss:
                    ss = ns
                    se = ne
        return s[ss:se+1]
