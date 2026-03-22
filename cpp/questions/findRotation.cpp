#include <vector>
#include <array>

using namespace std;

class Solution {
private:
    static constexpr std::array<std::array<int, 2>, 4> dirs = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int t=0; t<4; ++t) {
            int tr = t<=1 ? 0 : n-1;
            int tc = 1<=t&&t<=2 ? n-1 : 0;
            int td = t;
            int md = 0;
            int mr = 0;
            int mc = 0;
            int l = 0;
            int p = 0;
            for (; p<n*n; ++p) {
                if (mat[mr][mc] != target[tr][tc]) {
                    break;
                }
                mr += dirs[md][0];
                mc += dirs[md][1];
                tr += dirs[td][0];
                tc += dirs[td][1];
                switch (md) {
                    case 0:
                        if (mc==n-l-1) {
                            md = 1;
                            td = (td + 1) % 4;
                        }
                        break;
                    case 1:
                        if (mr == n-l-1) {
                            md = 2;
                            td = (td + 1) % 4;
                        }
                        break;
                    case 2:
                        if (mc == l) {
                            md = 3;
                            td = (td + 1) % 4;
                        }
                        break;
                    case 3:
                        if (mr == 1+l) {
                            md = 0;
                            ++l;
                            td = (td + 1) % 4;
                        }
                        break;
                }
            }
            if (p == n*n) {
                return true;
            }
        }
        return false;
    }
};
