#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int ss = s.size();
        std::vector<bool> dp(ss+1, false);
        dp[0] = true;
        for (int i=1; i<ss+1; ++i) {
            for (const auto& w: wordDict) {
                const int ws = w.size();
                const int sp = i - ws;
                if (sp>=0 && dp[sp] && s.substr(sp, ws)==w) {
                    dp[i] = true;
                }
            }
        }
        return dp[ss];
    }
};
