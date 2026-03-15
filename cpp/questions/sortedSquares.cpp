#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (r == 0) {
            nums[0] *= nums[0];
            return nums;
        }
        std::vector<int> ans(nums.size(), 0);
        nums[l] *= nums[l];
        nums[r] *= nums[r];
        for (int p=r; p>1; --p) {
            if (nums[r] > nums[l]) {
                ans[p] = nums[r];
                --r;
                nums[r] *= nums[r];
            } else {
                ans[p] = nums[l];
                ++l;
                nums[l] *= nums[l];
            }
        }
        ans[1] = std::max(nums[l], nums[r]);
        ans[0] = std::min(nums[l], nums[r]);
        return ans;
    }
};
