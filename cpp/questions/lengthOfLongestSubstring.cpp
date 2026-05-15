#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int fg[128] = {0};
        int ans = 0;
        while (r < s.size()) {
            auto& rfg = fg[s[r]];
            if (++rfg == 2) {
                ans = std::max(ans, r-l);
                while (fg[s[r]] > 1) {
                    fg[s[l++]]--;
                }
            }
            ++r;
        }
        ans = std::max(ans, r-l);
        return ans;
    }
};
