#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rs = matrix.size();
        int cs = matrix[0].size();
        for (int r=1; r<rs; ++r) {
            for (int c=0; c<cs; ++c) {
                matrix[r][c] = matrix[r][c] ? matrix[r-1][c]+1 : 0;
            }
        }
        int ans = 0;
        for (int r=0; r<rs; ++r) {
            std::sort(matrix[r].begin(), matrix[r].end(), std::less<int>());
            for (int c=0; c<cs; ++c) {
                ans = std::max(ans, (cs-c)*matrix[r][c]);
            }
        }
        return ans;
    }
};
