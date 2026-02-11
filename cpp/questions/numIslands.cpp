class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cl = grid.size();
        int rl = grid[0].size();
        int ans = 0;
        auto marklands = [&](this auto&& marklands, int c, int r) -> void {
            grid[c][r] = '2';
            if (c>0 && grid[c-1][r]=='1') {
                marklands(c-1, r);
            }
            if (c<cl-1 && grid[c+1][r]=='1') {
                marklands(c+1, r);
            }
            if (r>0 && grid[c][r-1]=='1') {
                marklands(c, r-1);
            }
            if (r<rl-1 && grid[c][r+1]=='1') {
                marklands(c, r+1);
            }
        };
        for (int cp=0; cp<cl; cp++) {
            for (int rp=0; rp<rl; rp++) {
                if (grid[cp][rp] == '1') {
                    marklands(cp, rp);
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
