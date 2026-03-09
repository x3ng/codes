#include <string>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int ss1 = s1.size();
        int ss2 = s2.size();
        int ss3 = s3.size();
        if (ss1+ss2 != ss3) {
            return false;
        }
        std::vector<std::vector<std::vector<bool>>> vis(ss1+1, std::vector<std::vector<bool>>(ss2+1, std::vector<bool>(2, false)));
        std::function<bool(int, int, bool)> dfs = [&](int p1, int p2, bool c) -> bool {
            vis[p1][p2][c] = true;
            std::string& s = c ? s2 : s1;
            int& p = c ? p2 : p1;
            int& rp = c ? p1 : p2;
            int ss = c ? ss2 : ss1;
            int rs = c ? ss1 : ss2;
            ++p;
            int mp = p1 + p2;
            if (rp == rs) {
                while (s[p-1]==s3[mp-1] && p<=ss) {
                    ++p;
                    ++mp;
                }
                return p == ss+1;
            }
            while (s[p-1]==s3[mp-1] && p<=ss) {
                if (!vis[p1][p2][!c] && dfs(p1, p2, !c)) {
                    return true;
                }
                ++p;
                ++mp;
            }
            return false;
        };
        return dfs(0, 0, true) || dfs(0, 0, false);
    }
};
