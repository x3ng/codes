#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        int maxn = INT_MIN;
        for (auto& row: grid) {
            maxn = std::max(maxn, *max_element(row.begin(), row.end()));
        }
        std::vector<int> rowc(c+1, INT_MAX);               
        std::vector<int> gmj(maxn+2, INT_MAX);
        std::vector<int> cmj(maxn+1, INT_MAX);
        for (int j=0; j<=k; j++) {
            std::fill(rowc.begin(), rowc.end(), INT_MAX);
            rowc[1] = -grid[0][0];
            for (int ri=0; ri<r; ri++) {
                for (int ci=0; ci<c; ci++) {
                    int cv = grid[ri][ci];
                    rowc[ci+1] = std::min(std::min(rowc[ci], rowc[ci+1])+cv, gmj[cv]);
                    cmj[cv] = std::min(cmj[cv], rowc[ci+1]);
                }
            }
            for (int js=maxn; js>=0; js--) {
                gmj[js] = std::min(gmj[js+1], cmj[js]);
            }
        }
        return rowc[c];
    }
};
