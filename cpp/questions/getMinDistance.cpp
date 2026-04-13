#include <vector>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int l = start;
        int r = start;
        while (1) {
            if (l>=0 && nums[l--]==target) {
                return start - l - 1;
            } else if (r<n && nums[r++]==target) {
                return r - start - 1;
            }
        }
        return -1;
    }
};
