#include <string>
#include <functional>

using namespace std;

class Solution {
private:
    int pairString(std::string& s, int& ss, int& l, int& r) {
        while (l>=0 && r<ss && s[l]==s[r]) {
            l--;
            r++;
        }
        l++;
        r--;
        return r-l;
    }
public:
    string longestPalindrome(string s) {
        int ss = s.size();
        int l = 0;
        int r = 0;
        int rml = r - l;
        for (int p=0; p<ss-rml/2; ++p) {
            int lp = p;
            int rp = p;
            int crl = pairString(s, ss, lp, rp);
            if (crl > rml) {
                l = lp;
                r = rp;
                rml = crl;
            }
            lp = p;
            rp = p + 1;
            crl = pairString(s, ss, lp, rp);
            if (crl > rml) {
                l = lp;
                r = rp;
                rml = crl;
            }
        }
        return s.substr(l, rml+1);
    }
};
