#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int ss = s.size();
        int ts = t.size();
        int cc[128] = {0};
        int df = 0;
        for (const char c: t) {
            if (cc[c]-- == 0) {
                ++df;
            }
        }
        int as = -1;
        int ms = ss;
        int l = 0;
        int r = 0;
        while (r < ss) {
            if (++cc[s[r++]] == 0) {
                --df;
            }
            if (df == 0) {
                while (cc[s[l++]]-- != 0) {}
                ++df;
                if (r-l < ms) {
                    ms = r-l;
                    as = l;
                }
            }
        }
        return as==-1 ? "" : s.substr(as-1, ms+1);
    }
};
