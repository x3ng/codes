#include <vector>
#include <functional>

using namespace std;

class Solution {
private:
    static constexpr int DIR[4][2] = {{-1, 0}, {0 ,1}, {1, 0}, {0, -1}};
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::function<bool(int, int, int, int, char)> dfs = [&](int r, int c, int pr, int pc, char m) -> bool {
            const char s = grid[r][c];
            grid[r][c] = m;
            bool af = false;
            for (int d=0; d<4; ++d) {
                int cr = r + DIR[d][0];
                int cc = c + DIR[d][1];
                if (cr<0 || cr>=rs || cc<0 || cc>=cs || (cr==pr && cc==pc)) {
                    continue;
                }
                if (grid[cr][cc] == m) {
                    af = true;
                } else if (grid[cr][cc] == s) {
                    af = dfs(cr, cc, r, c, m);
                }
                if (af) {
                    return true;
                }
            }
            return false;
        };
        for (int r=0; r<rs; ++r) {
            for (int c=0; c<cs; ++c) {
                if (grid[r][c] <= 'z' && dfs(r, c, -1, -1, static_cast<char>(grid[r][c]+26))) {
                    return true;
                }
            }
        }
        return false;
    }
};
