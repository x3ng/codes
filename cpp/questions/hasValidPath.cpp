#include <vector>
#include <functional>

using namespace std;

class Solution {
private:
    static constexpr int BDS[7][2][2] = {
        {},
        {{0, -1}, {0, 1}},
        {{-1, 0}, {1, 0}},
        {{0, -1}, {1, 0}},
        {{0, 1}, {1, 0}},
        {{-1, 0}, {0, -1}},
        {{-1, 0}, {0, 1}}
    };
    
    bool cMT(int b, int dr, int dc) {
        return (dr==BDS[b][0][0] && dc==BDS[b][0][1]) || (dr==BDS[b][1][0] && dc==BDS[b][1][1]);
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::vector<std::vector<bool>> vis(rs, std::vector<bool>(cs, false));

        std::function<bool(int, int)> dfs = [&](int cr, int cc) -> bool {
            if (cr==rs-1 && cc==cs-1) {
                return true;
            }
            const auto cb = grid[cr][cc];
            vis[cr][cc] = true;
            for (const auto d: BDS[cb]) {
                int nr = cr + d[0];
                int nc = cc + d[1];
                if (nr<0 || nr>=rs || nc<0 || nc>=cs || vis[nr][nc]) {
                    continue;
                }
                if (cMT(grid[nr][nc], -d[0], -d[1])) {
                    if (dfs(nr, nc)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs(0, 0);
    }
};
