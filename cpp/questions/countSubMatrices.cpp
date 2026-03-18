#include <vector>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rs = grid.size();
        int cs = grid[0].size();
        if (grid[0][0] > k) {
            return 0;
        }
        int ans = 1;
        for (int c=1; c<cs; ++c) {
            grid[0][c] += grid[0][c-1];
            if (grid[0][c] > k) {
                break;
            }
            ++ans;
        }
        for (int r=1; r<rs; ++r) {
            grid[0][0] += grid[r][0];
            if (grid[0][0] > k) {
                break;
            }
            ++ans;
            for (int c=1; c<cs; ++c) {
                grid[r][c] += grid[r][c-1];
                grid[0][c] += grid[r][c];
                if (grid[0][c] > k) {
                    break;
                }
                ++ans;
            }
        }
        return ans;
    }
};
