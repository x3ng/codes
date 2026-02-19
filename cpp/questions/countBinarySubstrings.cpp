class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int pp = 0;
        int pl = 0;
        for (int p=1; p<n; p++) {
            if (s[p] != s[p-1]) {
                int tp = p - pp;
                ans += std::min(tp, pl);
                pp = p;
                pl = tp;
            }
        }
        ans += std::min(n-pp, pl);
        return ans;
    }
};
