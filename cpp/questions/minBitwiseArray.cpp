class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, -1);
        for (int p=0; p<n; p++) {
            if (nums[p] & 1) {
                int tmp = nums[p];
                int cnt = 0;
                while (tmp & 1) {
                    cnt++;
                    tmp >>= 1;
                }
                ans[p] = nums[p] & ~(1<<(cnt-1));
            }
        }
        return ans;
    }
};
