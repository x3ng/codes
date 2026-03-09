#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        for (int c=1; c<cs; ++c) {
            grid[0][c] += grid[0][c-1];
        }
        for (int r=1; r<rs; ++r) {
            grid[0][0] += grid[r][0];
            for (int c=1; c<cs; ++c) {
                grid[0][c] = std::min(grid[0][c], grid[0][c-1]) + grid[r][c];
            }
        }
        return grid[0][cs-1];
    }
};
