#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs = nums[0];
        int curs = 0;
        for (const auto n: nums) {
            if (curs < 0) {
                curs = n;
            } else {
                curs = curs + n;
            }
            maxs = std::max(maxs, curs);
        }
        return maxs;
    }
};
