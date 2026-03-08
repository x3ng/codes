#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ns = nums.size();
        int ans = 1;
        std::vector<int> dp(ns, 1);
        for (int r=1; r<ns; ++r) {
            int rv = nums[r];
            for (int l=r-1; l>=0; --l) {
                if (nums[l] < rv) {
                    dp[r] = std::max(dp[l]+1, dp[r]);
                }
            }
            ans = std::max(ans, dp[r]);
        }
        return ans;
    }
};
