#include <vector>

class Solution {
private:
    static constexpr long long MOD = 1e9+7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        std::vector<std::vector<std::vector<long long>>> dp(zero+1, std::vector<std::vector<long long>>(one+1, std::vector<long long>(2, 0)));
        for (int p=0; p<=std::min(zero, limit); ++p) {
            dp[p][0][0] = 1;
        }
        for (int p=0; p<=std::min(one, limit); ++p) {
            dp[0][p][1] = 1;
        }
        for (int p0=1; p0<=zero; ++p0) {
            for (int p1=1; p1<=one; ++p1) {
                dp[p0][p1][0] = dp[p0-1][p1][0] + dp[p0-1][p1][1];
                dp[p0][p1][1] = dp[p0][p1-1][0] + dp[p0][p1-1][1];
                dp[p0][p1][0] += p0>limit ? MOD-dp[p0-limit-1][p1][1] : 0;
                dp[p0][p1][1] += p1>limit ? MOD-dp[p0][p1-limit-1][0] : 0;
                dp[p0][p1][0] %= MOD;
                dp[p0][p1][1] %= MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
