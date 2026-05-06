#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int rs = boxGrid.size();
        int cs = boxGrid[0].size();
        std::vector<std::vector<char>> ans(cs, std::vector<char>(rs, '.'));

        for (int r=0; r<rs; ++r) {
            const int tr = rs - 1 - r;
            int sc = 0;
            for (int c=0; c<cs; ++c) {
                if (boxGrid[r][c] == '*') {
                    ans[c][tr] = '*';
                    while (sc) {
                        ans[c-sc][tr] = '#';
                        --sc;
                    }
                    sc = 0;
                } else if (boxGrid[r][c] == '#') {
                    ++sc;
                }
            }
            while (sc) {
                ans[cs-sc][tr] = '#';
                --sc;
            }
        }
        
        return ans;
    }
};
