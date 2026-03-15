#include <array>
#include <vector>

using namespace std;

class Solution {
private:
    static constexpr std::array<std::array<int, 2>, 4> ds = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> ans(n, std::vector<int>(n));
        int l = 0;
        int d = 0;
        int r = 0;
        int c = 0;
        for (int p=1; p<=n*n; ++p) {
            ans[r][c] = p;
            r += ds[d][0];
            c += ds[d][1];
            switch (d) {
                case 0:
                    if (c == n-l-1) {
                        d = 1;
                    }
                    break;
                case 1:
                    if (r == n-l-1) {
                        d = 2;
                    }
                    break;
                case 2:
                    if (c == l) {
                        d = 3;
                    }
                    break;
                case 3:
                    if (r == l) {
                        d = 0;
                        ++r;
                        ++c;
                        ++l;
                    }
                    break;
                default:
                    break;
            }
        }
        return ans;
    }
};
