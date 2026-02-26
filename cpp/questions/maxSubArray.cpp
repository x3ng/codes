class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ns = nums.size();
        int ans = nums[0];
        int pm = 0;
        for (const auto& n: nums) {
            pm = std::max(pm+n, n);
            ans = std::max(pm, ans);
        }
        return ans;
    }
};
