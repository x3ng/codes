class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ans;
        std::vector<int> tmp(k, 0);
        auto bt = [&](this auto&& bt, int p, int s) -> void {
            if (p == k) {
                ans.push_back(tmp);
                return;
            }
            for (int i=s; i<=n+1+p-k; i++) {
                tmp[p] = i;
                bt(p+1, i+1);
            }
        };
        bt(0, 1);
        return ans;
    }
};
