#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static constexpr int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        int fresh = 0;
        std::deque<std::pair<int, int>> dq;
        for (int r=0; r<rs; ++r) {
            for (int c=0; c<cs; ++c) {
                if (grid[r][c] == 2) {
                    dq.push_back(std::make_pair(r, c));
                } else if (grid[r][c] == 1) {
                    ++fresh;
                }
            }
        }
        int ans = 0;
        while (!dq.empty()) {
            int cl = dq.size();
            while (cl--) {
                auto [r, c] = dq.front();
                dq.pop_front();
                for (auto d: DIR) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr>=0 && nr<rs && nc>=0 && nc<cs && grid[nr][nc]==1) {
                        dq.push_back(std::make_pair(nr, nc));
                        grid[nr][nc] = 2;
                    }
                }
            }
            ans += dq.empty() ? 0 : 1;
            fresh -= dq.size();
        }
        return fresh==0 ? ans : -1;
    }
};
