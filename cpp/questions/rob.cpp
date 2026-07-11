#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ns = nums.size();
        std::array<int, 2> dp = {0, 0};
        for (const auto& n: nums) {
            int cr = dp[0] + n;
            dp[0] = std::max(dp[0], dp[1]);
            dp[1] = std::max(cr, dp[1]);
        }
        return std::max(dp[0], dp[1]);
    }
};
