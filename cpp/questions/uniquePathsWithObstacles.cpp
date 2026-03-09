#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rs = obstacleGrid.size();
        int cs = obstacleGrid[0].size();
        obstacleGrid[0][0] = obstacleGrid[0][0] ? 0 : 1;
        for (int c=1; c<cs; ++c) {
            obstacleGrid[0][c] = obstacleGrid[0][c] ? 0 : obstacleGrid[0][c-1];
        }
        for (int r=1; r<rs; ++r) {
            obstacleGrid[0][0] = obstacleGrid[r][0] ? 0 : obstacleGrid[0][0];
            for (int c=1; c<cs; ++c) {
                obstacleGrid[0][c] += obstacleGrid[r][c] ? -obstacleGrid[0][c] : obstacleGrid[0][c-1];
            }
        }
        return obstacleGrid[0][cs-1];
    }
};
