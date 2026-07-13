from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        ls = len(s)
        dp = [False] * (ls + 1)
        dp[0] = True
        for i in range(1, ls+1):
            for w in wordDict:
                lw = len(w)
                sp = i - lw
                if sp>=0 and dp[sp] and s[sp:i]==w:
                    dp[i] = True
        return dp[ls]
