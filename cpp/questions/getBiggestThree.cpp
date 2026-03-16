#include <vector>
#include <array>

using namespace std;

class Solution {
private:
    class M3 {
    public:
        std::array<int, 3> ns;

        void push(int n) {
            int p = 3;
            while (p > 0 && n >= ns[p-1]) {
                --p;
            }
            if (p > 2 || n == ns[p]) {
                return;
            }
            int tmp = 2;
            while (tmp > p) {
                ns[tmp] = ns[tmp-1];
                --tmp;
            }
            ns[p] = n;
        }

    };

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::vector<std::vector<std::pair<int, int>>> pres(rs+2, std::vector<std::pair<int, int>>(cs+2, {0, 0}));
        for (int r=1; r<=rs; ++r) {
            for (int c=1; c<=cs; ++c) {
                pres[r][c].first = pres[r-1][c-1].first + grid[r-1][c-1];
                pres[r][c].second = pres[r-1][c+1].second + grid[r-1][c-1];
            }
        }
        M3 m3n;
        for (int r=1; r<=rs; ++r) {
            int rl = (r + 1) / 2;
            for (int c=1; c<=cs; ++c) {
                int mb = std::min(rl, std::min(c, cs+1-c));
                m3n.push(grid[r-1][c-1]);
                for (int b=2; b<=mb; ++b) {
                    m3n.push(
                            pres[r][c].first - pres[r+1-b][c+1-b].first +
                            pres[r+1-b][c+1-b].second - pres[r+2-2*b][c].second +
                            pres[r-b][c+b-2].first - pres[r+1-2*b][c-1].first +
                            pres[r-1][c+1].second - pres[r-b][c+b].second
                            );
                }
            }
        }
        std::vector<int> ans;
        for (const auto& n: m3n.ns) {
            if (n) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};
