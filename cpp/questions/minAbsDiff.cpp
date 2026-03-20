#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rs = grid.size();
        int cs = grid[0].size();
        std::vector<std::vector<int>> ans(rs-k+1, std::vector<int>(cs-k+1, INT_MAX));
        for (int r=0; r<rs-k+1; ++r) {
            for (int c=0; c<cs-k+1; ++c) {
                std::vector<int> tmp;
                tmp.reserve(k * k);
                for (int ir=r; ir<r+k; ++ir) {
                    for (int ic=c; ic<c+k; ++ic) {
                        tmp.push_back(grid[ir][ic]);
                    }
                }
                std::sort(tmp.begin(), tmp.end(), std::greater<int>());
                if (tmp.front() == tmp.back()) {
                    ans[r][c] = 0;
                } else {
                    for (int p=0; p<tmp.size()-1; ++p) {
                        int td = tmp[p] - tmp[p+1];
                        ans[r][c] = td==0 ? ans[r][c] : std::min(ans[r][c], td);
                    }
                }
            }
        }
        return ans;
    }
};
