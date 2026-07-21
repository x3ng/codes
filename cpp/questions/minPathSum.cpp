#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::vector<int> rv(cs, INT_MAX);
        rv[0] = 0;
        for (int r=0; r<rs; ++r) {
            rv[0] += grid[r][0];
            for (int c=1; c<cs; ++c) {
                rv[c] = std::min(rv[c], rv[c-1]) + grid[r][c];
            }
        }
        return rv[cs-1];
    }
};
