#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i=1; i*i<=n; ++i) {
            const int c2 = i * i;
            for (int j=c2; j<=n; ++j) {
                dp[j] = std::min(dp[j], dp[j-c2]+1);
            }
        }
        return dp[n];
    }
};
