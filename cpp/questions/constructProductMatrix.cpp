#include <vector>

using namespace std;

class Solution {
private:
    static constexpr int MOD = 12345;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int gr = grid.size();
        int gc = grid[0].size();
        std::vector<std::vector<int>> ans(gr, std::vector<int>(gc));
        long long tmp = 1;
        for (int r=0; r<gr; ++r) {
            for (int c=0; c<gc; ++c) {
                ans[r][c] = tmp;
                tmp *= grid[r][c];
                tmp %= MOD;
            }
        }
        tmp = 1;
        for (int r=gr-1; r>=0; --r) {
            for (int c=gc-1; c>=0; --c) {
                ans[r][c] *= tmp;
                ans[r][c] %= MOD;
                tmp *= grid[r][c];
                tmp %= MOD;
            }
        }
        return ans;
    }
};
