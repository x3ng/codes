class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ls = len(s)
        dp = [0] * ls
        ans = 0
        for i in range(1, ls):
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = 2 + (dp[i-2] if i>=2 else 0)
                else:
                    p = i - dp[i-1] - 1
                    if p>=0 and s[p]=='(':
                        dp[i] = 2 + dp[i-1] + (dp[p-1] if p>=1 else 0)
                ans = max(ans, dp[i])
        return ans
