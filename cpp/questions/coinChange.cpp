#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount+1, 0);
        for (int s=1; s<=amount; ++s) {
            int mp = amount;
            for (const auto& c: coins) {
                if (c <= s) {
                    mp = std::min(mp, dp[s-c]);
                }
            }
            dp[s] = mp + 1;
        }
        return dp[amount]>amount ? -1 : dp[amount];
    }
};
