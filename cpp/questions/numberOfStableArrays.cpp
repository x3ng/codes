#include <vector>

class Solution {
private:
    static constexpr long long MOD = 1e9 + 7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        std::vector<std::vector<std::vector<long long>>> dp(zero+1, std::vector<std::vector<long long>>(one+1, std::vector<long long>(2, 0)));
        for (int p=0; p<=std::min(zero, limit); ++p) {
            dp[p][0][0] = 1;
        }
        for (int p=0; p<=std::min(one, limit); ++p) {
            dp[0][p][1] = 1;
        }
        for (int n1=1; n1<=one; ++n1) {
            for (int n0=1; n0<=zero; ++n0) {
                dp[n0][n1][0] = dp[n0-1][n1][1] + dp[n0-1][n1][0];
                dp[n0][n1][0] += n0>limit ? MOD-dp[n0-limit-1][n1][1] : 0;
                dp[n0][n1][0] %= MOD;
                dp[n0][n1][1] = dp[n0][n1-1][0] + dp[n0][n1-1][1];
                dp[n0][n1][1] += n1>limit ? MOD-dp[n0][n1-limit-1][0] : 0;
                dp[n0][n1][1] %= MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
