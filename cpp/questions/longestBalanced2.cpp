class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        int ss = s.size();
        for (int l=0; l<ss-ans; l++) {
            int cnt[26]{};
            for (int r=l; r<ss; r++) {
                int cc = ++cnt[s[r]-'a'];
                bool valid = true;
                for (int c: cnt) {
                    if (c && c != cc) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ans = std::max(ans, r-l+1);
                }
            }
        } 
        return ans;
    }
};
