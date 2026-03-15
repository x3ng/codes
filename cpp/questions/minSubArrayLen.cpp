#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ns = nums.size();
        int l = 0;
        int r = 0;
        int ws = 0;
        int ans = INT_MAX;
        for (; l<ns; ++l) {
            for (; r<ns && ws<target; ++r) {
                ws += nums[r];
            }
            if (ws >= target) {
                ans = std::min(ans, r-l);
            } else if (r == ns && ws<target) {
                return ans==INT_MAX ? 0 : ans;
            }
            ws -= nums[l];
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
