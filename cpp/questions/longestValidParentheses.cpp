#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ss = s.size();
        std::vector<int> dp(ss, 0);
        int ans = 0;
        for (int i=1; i<ss; ++i) {
            if (s[i] == ')') {
                if (s[i-1]=='(') {
                    dp[i] = (i>=2?dp[i-2]:0) + 2;
                } else {
                    int p = i - dp[i-1] - 1;
                    if (p>=0 && s[p]=='(') {
                        dp[i] = dp[i-1] + (p>=1?dp[p-1]:0) + 2;
                    }
                }
                ans = std::max(ans, dp[i]);
            }
        }
        return ans;
    }
};
