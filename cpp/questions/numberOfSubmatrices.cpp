#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::vector<int> stat(cs+1, 0);
        int ans = 0;
        int cc = cs + 1;
        for (int r=0; r<rs; ++r) {
            int cd = 0;
            for (int c=1; c<=cs; ++c) {
                switch (grid[r][c-1]) {
                    case '.':
                        break;
                    case 'X':
                        cd += 1;
                        cc = std::min(cc, c);
                        break;
                    case 'Y':
                        cd -= 1;
                        cc = std::min(cc, c);
                        break;
                }
                stat[c] += cd;
                ans += stat[c]==0 && c>=cc;
            }
        }
        return ans;
    }
};
