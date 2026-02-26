class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int dif = nums[m] - target;
            if (dif == 0) {
                return m;
            } else if (dif > 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return nums[l] >= target ? l : l+1;
    }
};
