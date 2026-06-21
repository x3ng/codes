#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int cs = candidates.size();
        std::vector<std::vector<int>> ans;        
        std::vector<int> tmp;
        std::function<void(int, int)> bc = [&](int p, int tgt) -> void {
            if (tgt == 0) {
                ans.emplace_back(tmp);
                return;
            }
            for (int np=p; np<cs; ++np) {
                int nv = candidates[np];
                if (nv > tgt) {
                    continue;
                }
                tmp.push_back(nv);
                bc(np, tgt-nv);
                tmp.pop_back();
            }
        };
        bc(0, target);
        return ans;
    }
};
