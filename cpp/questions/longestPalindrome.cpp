#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    std::pair<int, int> pairString(const std::string& s, const int& ss, int l, int r) {
        while (l>=1 && r<ss-1 && s[l-1]==s[r+1]) {
            --l;
            ++r;
        }
        return std::pair(l, r);
    }
public:
    string longestPalindrome(string s) {
        int ss = s.size();
        int as = 0;
        int al = 0;
        for (int i=0; i<ss; ++i) {
            auto [ns, ne] = pairString(s, ss, i, i);
            if (ne-ns > al) {
                as = ns;
                al = ne - ns;
            }
            if (i<ss-1 && s[i]==s[i+1]) {
                auto [ns, ne] = pairString(s, ss, i, i+1);
                if (ne-ns > al) {
                    as = ns;
                    al = ne - ns;
                }
            }
        }
        return s.substr(as, al+1);
    }
};
