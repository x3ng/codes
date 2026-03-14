#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r = nums.size() - 1;
        if (r < 0) {
            return 0;
        }
        int l = 0;
        for (; l<r; ++l) {
            if (nums[l] == val) {
                while (r>l && nums[r]==val) {
                    --r;
                }
                std::swap(nums[l], nums[r]);
            }
        }
        return nums[r]==val ? r : r+1;
    }
};
