#include <vector>

using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for (int s=0; s<nums.size(); s++) {
            std::set<int> nst = {nums[s]};
            int d = nums[s] & 1 ? 1 : -1;
            for (int e=s+1; e<nums.size(); e++) {
                auto it = nst.find(nums[e]);
                if (it == nst.end()) {
                    d += nums[e] & 1 ? 1 : -1;
                    nst.insert(nums[e]);
                }
                if (d == 0) {
                    ans = std::max(ans, e-s+1);
                }
            }
        }
        return ans;
    }
};
