#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tn = 0;
        for (const auto& n: nums) {
            tn += n;
        }
        if (tn%2 == 1) {
            return false;
        }
        tn /= 2;
        int cs = 0;
        std::vector<bool> dp(tn+1, false);
        dp[0] = true;
        for (const auto& n: nums) {
            cs += n;
            for (int i=std::min(cs, tn); i>=n; --i) {
                if (dp[i-n]) {
                    dp[i] = true;
                }
            }
            if (dp[tn]) {
                return true;
            }
        }
        return false;
    }
};
