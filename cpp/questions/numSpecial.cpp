#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rs = mat.size();
        int cs = mat[0].size();
        std::vector<bool> valcol(cs, false);
        std::vector<int> colcnt(cs, 0);
        for (int r=0; r<rs; ++r) {
            int cnt = 0;
            int cp = -1;
            for (int c=0; c<cs; ++c) {
                cnt += mat[r][c];
                colcnt[c] += mat[r][c];
                cp = mat[r][c]==1? c : cp;
            }
            if (cnt == 1) {
                valcol[cp] = true;
            }
        }
        int ans = 0;
        for (int p=0; p<cs; ++p) {
            ans += valcol[p] ? colcnt[p]==1 ? 1 : 0 : 0;
        }
        return ans;
    }
};
