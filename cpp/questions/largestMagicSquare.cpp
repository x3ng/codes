class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> psr(m, std::vector<int>(n+1, 0));
        std::vector<std::vector<int>> psc(m+1, std::vector<int>(n, 0));
        std::vector<std::vector<int>> lurb(m+1, std::vector<int>(n+1, 0));
        std::vector<std::vector<int>> lbru(m+1, std::vector<int>(n+1, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                psr[i][j+1] = psr[i][j] + grid[i][j];
                psc[i+1][j] = psc[i][j] + grid[i][j];
                lurb[i+1][j+1] = lurb[i][j] + grid[i][j];
                lbru[m-i-1][j+1] = lbru[m-i][j] + grid[m-i-1][j];
            }
        }
        for (int k=std::min(m, n); k>1; k--) {
            for (int i=0; i<=m-k; i++) {
                for (int j=0; j<=n-k; j++) {
                    int ss = lurb[i+k][j+k]-lurb[i][j];
                    if (ss != lbru[i][j+k]-lbru[i+k][j]) {
                        continue;
                    }
                    int rb;
                    for (rb=0; rb<k; rb++) {
                        if (ss != psr[i+rb][j+k] - psr[i+rb][j]) {
                            break;
                        }
                    }
                    if (rb != k) {
                        continue;
                    }
                    int cb;
                    for (cb=0; cb<k; cb++) {
                        if (ss != psc[i+k][j+cb] - psc[i][j+cb]) {
                            break;
                        }
                    }
                    if (cb != k) {
                        continue;
                    }
                    return k;
                }
            }
        }
        return 1;
    }
};
