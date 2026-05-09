#include <vector>

using namespace std;

class Solution {
private:
    static constexpr int DIR[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::vector<int> ge(2*(rs+cs-2));
        int ls = std::min(rs, cs) / 2;
        for (int l=0; l<ls; ++l) {
            int cr = rs - l * 2;
            int cc = cs - l * 2;
            int cl = 2 * (cr + cc - 2);
            int km = k % cl;
            if (km == 0) {
                continue;
            }
            int r = l;
            int c = l;
            int cnt = 0;
            for (const auto& [x, y]: DIR) {
                for (int i=0; i<cc-1; ++i) {
                    ge[cnt++] = grid[r][c];
                    r += x;
                    c += y;
                }
                std::swap(cr, cc);
            }
            int si = 0;
            for (const auto& [x, y]: DIR) {
                for (int i=0; i<cc-1; ++i) {
                    grid[r][c] = ge[(km+si++)%cl];
                    r += x;
                    c += y;
                }
                std::swap(cr, cc);
            }
        }
        return grid;
    }
};
