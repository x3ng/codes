class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ns = nums.size();
        if (ns == 0) {
            return {-1, -1};
        }
        int l = 0;
        int r = ns - 1;
        int m = (l + r) / 2;
        while (l < r) {
            int diff = nums[m] - target;
            if (diff == 0) {
                break;
            } else if (diff > 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
            m = (l + r) / 2;
        }
        if (nums[m] != target) {
            return {-1, -1};
        } else {
            for (l=m; l>=0 && nums[l]==target; --l) {}
            for (r=m; r<ns && nums[r]==target; ++r) {}
            return {l+1, r-1};
        }
    }
};
