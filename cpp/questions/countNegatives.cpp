class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // int ans = 0;
        // int rs = grid.size();
        // int cs = grid[0].size();
        // int r = 0;
        // int c = cs-1;
        // while (r<rs && grid[r][c]>=0) {
        //     r++;
        // }
        // while (r < rs) {
        //     while (c>=0 && grid[r][c]<0) {
        //         c--;
        //     }
        //     ans += cs - c -1;
        //     r++;
        // }
        // return ans;
        int ans = 0;
        int rb = grid.size()-1;
        int cr = grid[0].size()-1;
        int cl = cr;
        int ru = 0;
        while (ru<rb && grid[ru][c]>=0) {
            ru++;
        }
        while (ru<rb && grid[rb][0]<0) {
            rb--;
            ans += grid[0].size();
        }
        while (ru <= rb) {
            while (cl>=0 && grid[ru][cl]<0) {
                cl--;
            }
            ans += cr - cl;
            ru++;
        }
        return ans;
    }
};
