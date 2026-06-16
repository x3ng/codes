#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::function<void(int, int)> step = [&](int r, int c) -> void {
            if (r<0 || r>=rs || c<0 || c>=cs || grid[r][c] == '0') {
                return;
            }
            grid[r][c] = '0';
            step(r-1, c);
            step(r+1, c);
            step(r, c-1);
            step(r, c+1);
        };
        int ans = 0;
        for (int r=0; r<rs; ++r) {
            for (int c=0; c<cs; ++c) {
                if (grid[r][c] == '1') {
                    ++ans;
                    step(r, c);
                }
            }
        }
        return ans; 
    }
};
