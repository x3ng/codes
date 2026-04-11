#include <vector>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        std::vector<int> cnt(n+1, 0);
        int ans = -1;
        while (r < n) {
            if (++cnt[nums[r++]] >= 3) {
                while (--cnt[nums[l++]] < 2) {}
                ans = 2 * (r - l);
            } else if (ans != -1) {
                --cnt[nums[l++]];
            }
        }
        return ans;
    }
};
