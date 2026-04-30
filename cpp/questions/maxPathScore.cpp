#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::vector<std::vector<std::vector<int>>> memo(rs, std::vector<std::vector<int>>(cs, std::vector<int>(k+1, -2)));
        std::function<int(int, int, int)> dfs = [&](int r, int c, int k) -> int {
            if (r>=rs || c>=cs) {
                return -1;
            }
            int& cv = memo[r][c][k];
            if (cv != -2) {
                return cv;
            }
            const int gv = grid[r][c];
            k -= gv!=0;
            if (k < 0) {
                cv = -1;
                return cv;
            }
            if (r==rs-1 && c==cs-1) {
                cv = gv;
                return cv;
            }
            int rv = dfs(r, c+1, k);
            int dv = dfs(r+1, c, k);
            if (rv==-1 && dv==-1) {
                cv = -1;
                return cv;
            }
            cv = std::max(rv, dv) + gv;
            return cv;
        };
        return dfs(0, 0, k);
    }
};
