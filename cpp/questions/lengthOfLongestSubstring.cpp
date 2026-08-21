#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int fg[128];
        memset(fg, -1, sizeof(fg));
        int ans = 0;
        int l = 0;
        int r = 0;
        for (; r<s.size(); ++r) {
            const char rc = s[r];
            if (fg[rc] >= 0) {
                ans = std::max(ans, r-l);
                l = std::max(l, fg[rc] + 1);
            }
            fg[rc] = r;
        }
        ans = std::max(ans, r-l);
        return ans;
    }
};
