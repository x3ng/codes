#include <vector>

using namesapce std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int l = 0;
        int maxl = 0;
        for (int r=0; r<nums.size(); r++) {
            while (nums[l]*1L*k < nums[r]) {
                l++;
            }
            maxl = std::max(maxl, r-l+1);
        }
        return nums.size() - maxl;
    }
};
