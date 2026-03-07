#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ns = nums.size();
        if (ns < 2) {
            return nums[0];
        }
        std::array<int, 2> dp;
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int p=2; p<ns; ++p) {
            int tmp = dp[0] + nums[p];
            dp[0] = dp[1];
            dp[1] = std::max(tmp, dp[1]);
        }
        return dp[1];
    }
};
