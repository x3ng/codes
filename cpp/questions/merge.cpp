#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) ->  bool { return a[0] < b[0]; });        
        std::vector<std::vector<int>> ans;
        for (const auto& v: intervals) {
            if (ans.empty() || v[0] > ans.back()[1]) {
                ans.push_back(v);
            } else {
                ans.back()[1] = std::max(ans.back()[1], v[1]);
            }
        }
        return ans;
    }
};
