#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::vector<int> t0c(rs, cs);
        for (int r=0; r<rs; ++r) {
            int c = cs - 1;
            for (; c>=0; --c) {
                if (grid[r][c] == 1) {
                    t0c[r] = cs - c - 1;
                    break;
                }
            }
        }
        int ans = 0;
        for (int p=0; p<rs; ++p) {
            int sp = p;
            for (; sp<rs; ++sp) {
                if (t0c[sp] >= rs-p-1) {
                    ans += sp - p;
                    for (int tp=sp; tp>p; --tp) {
                        t0c[tp] = t0c[tp-1];
                    }
                    break;
                }
            }
            if (sp == rs) {
                return -1;
            }
        }
        return ans;
    }
};
