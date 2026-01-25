class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        std::sort(nums.begin(), nums.end());
        for (int p=k-1; p<nums.size(); p++) {
            int curr_diff = nums[p] - nums[p-k+1];
            if (curr_diff < ans) {
                ans = curr_diff;
            }
        }
        return ans;
    }
};
