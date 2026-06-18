#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int ns = nums.size();
        std::vector<std::vector<int>> ans = {{}};        
        std::vector<int> tmp;
        tmp.reserve(ns);
        std::function<void(int)> bs = [&](int p) -> void {
            tmp.emplace_back(nums[p]);
            ans.emplace_back(tmp);
            for (int i=p+1; i<ns; ++i) {
                bs(i);
            }
            tmp.pop_back();
        };
        for (int i=0; i<ns; ++i) {
            bs(i);
        }
        return ans;
    }
};
