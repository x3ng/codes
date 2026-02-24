class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int nss = nums.size();
        std::vector<std::vector<int>> ans;
        auto bt = [&](this auto&& bt, int p) -> void {
            if (p == nss) {
                ans.push_back(nums);
                return;
            }
            for (int i=p; i<nss; ++i) {
                std::swap(nums[p], nums[i]);
                bt(p+1);
                std::swap(nums[p], nums[i]);
            }
        };
        bt(0);
        return ans;
    }
};
