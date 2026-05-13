#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::unordered_set<int> hs(nums.begin(), nums.end());
        int ans = 0;
        for (int n: hs) {
            if (!hs.count(n-1)) {
                int cn = n;
                int cl = 1;
                while (hs.count(cn+1)) {
                    ++cn;
                    ++cl;
                }
                ans = std::max(ans, cl);
            }
        }
        return ans;
    }
};
