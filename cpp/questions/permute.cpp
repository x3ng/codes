#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int ns = nums.size();
        std::vector<std::vector<int>> ans;
        std::vector<bool> flag(ns);        
        std::vector<int> tmp(ns);
        std::function<void(int)> bv = [&](int p) -> void {
            if (p == ns) {
                ans.emplace_back(tmp);
            }
            for (int i=0; i<ns; ++i) {
                if (!flag[i]) {
                    tmp[p] = nums[i];
                    flag[i] = true;
                    bv(p+1);
                    flag[i] = false;
                }
            }
        };
        bv(0);
        return ans;
    }
};
