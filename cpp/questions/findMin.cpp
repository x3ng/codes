class Solution {
public:
    int findMin(vector<int>& nums) {
        int nfp = nums.size() - 1;
        int l = 0;
        int r = nfp;
        while (l < r) {
            int m = (l + r) / 2;
            int diff = nums[m] - nums[nfp];
            if (diff > 0) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return nums[l] > nums[nfp] ? nums[l+1] : nums[l];
    }
};
