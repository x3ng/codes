class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ns = nums.size();
        if (ns == 1) {
            return nums[0]==target ? 0 : -1;
        }
        int r = 0;
        for (; r<ns-1 && nums[r]<nums[r+1]; ++r) {}      
        int l = r + 1;
        r += ns;
        while (l < r) {
            int m = ((l + r) / 2);
            int dif = nums[m%ns] - target;
            if (dif == 0) {
                return m % ns;
            } else if (dif > 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = l % ns;
        return nums[l]==target ? l : -1;
    }
};
