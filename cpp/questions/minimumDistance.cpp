#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> pos;
        int ans = INT_MAX;
        for (int p=0; p<nums.size(); ++p) {
            const int& n = nums[p];
            pos[n].push_back(p);
            const int& cs = pos[n].size();
            if (cs >= 3) {
                ans = std::min(ans, p-pos[n][cs-3]);
            }
        }
        return ans==INT_MAX ? -1 : 2*ans;
    }
};
