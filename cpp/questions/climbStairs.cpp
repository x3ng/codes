#include <array>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 0;
        }
        std::array<int ,2> dp = {0, 1};
        while (n--) {
            int tmp = dp[1];
            dp[1] += dp[0];
            dp[0] = tmp;
        }
        return dp[1];
    }
};
