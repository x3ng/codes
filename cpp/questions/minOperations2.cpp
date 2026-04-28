#include <vector>
#include <ranges>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rs = grid.size();
        int cs = grid[0].size();
        int n = rs * cs;
        int ans = 0;
        std::vector<int> tmp(n);
        int rn = grid[0][0] % x;
        for (int r=0; r<rs; ++r) {
            for (int c=0; c<cs; ++c) {
                if (grid[r][c]%x != rn) {
                    return -1;
                }
                tmp[r*cs+c] = grid[r][c];
            }
        }
        std::ranges::nth_element(tmp, tmp.begin()+n/2);
        int d = tmp[n/2];
        for (int p=0; p<n/2; ++p) {
            int df = d - tmp[p];
            ans += df;
        }
        for (int p=n/2+1; p<n; ++p) {
            int df = tmp[p] - d;
            ans += df;
        }
        return ans / x;
    }
};
