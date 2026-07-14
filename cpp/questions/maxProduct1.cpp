#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::pair<int, int> dp = {nums[0], nums[0]};
        int ans = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            int n = nums[i];
            auto [l, h] = dp;
            dp.first = std::min(std::min(l*n, h*n), n);
            dp.second = std::max(std::max(l*n, h*n), n);
            ans = std::max(ans, dp.second);
        }
        return ans;
    }
};
