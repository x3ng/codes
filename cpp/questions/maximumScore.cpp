#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<long long>> col_sum(n, std::vector<long long>(n+1));

        for (int j=0; j<n; ++j) {
            for (int i=0; i<n; ++i) {
                col_sum[j][i+1] = col_sum[j][i] + grid[i][j];
            }
        }

        std::vector<std::vector<std::array<long long, 2>>> f(n, std::vector<std::array<long long, 2>>(n+1));

        for (int j=0; j<n-1; ++j) {
            long long pre_max = f[j][0][1] - col_sum[j][0];
            for (int pre=1; pre<=n; ++pre) {
                f[j+1][pre][0] = f[j+1][pre][1] = std::max(f[j][pre][0], pre_max+col_sum[j][pre]);
                pre_max = std::max(pre_max, f[j][pre][1]-col_sum[j][pre]);
            }

            long long suf_max = f[j][n][0] + col_sum[j+1][n];
            for (int pre=n-1; pre>0; --pre) {
                f[j+1][pre][0] = std::max(f[j+1][pre][0], suf_max-col_sum[j+1][pre]);
                suf_max = std::max(suf_max, f[j][pre][0]+col_sum[j+1][pre]);
            }

            f[j+1][0][0] = suf_max;
            f[j+1][0][1] = std::max(f[j][0][0], f[j][n][0]);
        }

        return std::max(f[n-1][0][0], f[n-1][n][0]);
    }
};
