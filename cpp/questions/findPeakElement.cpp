class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int p = 1;
        for (; p<nums.size(); ++p) {
            if (nums[p] < nums[p-1]) {
                break;
            }
        }
        return p-1;
    }
};
