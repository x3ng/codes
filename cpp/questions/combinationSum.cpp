class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int cs = candidates.size();
        std::vector<std::vector<int>> ans;
        std::vector<int> tmp;
        auto bt = [&](this auto&& bt, int target, int s) -> void {
            if (target <= 0) {
                if (target == 0) {
                    ans.emplace_back(tmp);
                }
                return;
            }
            for (int p=s; p<cs; ++p) {
                int c = candidates[p];
                tmp.emplace_back(c);
                bt(target-c, p);
                tmp.pop_back();
            }
        };
        bt(target, 0);
        return ans;
    }
};
