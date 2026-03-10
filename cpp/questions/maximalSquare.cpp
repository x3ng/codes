#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rs = matrix.size();
        int cs = matrix[0].size();
        int ans = 0;
        std::vector<std::vector<int>> dp(cs, std::vector<int>(2, 0));
        for (int r=0; r<rs; ++r) {
            int ps = 0;
            int pr = 0;
            for (int c=0; c<cs; ++c) {
                pr += matrix[r][c]=='1' ? 1 : -pr;
                dp[c][0] += matrix[r][c]=='1' ? 1 : -dp[c][0];
                int mb = std::min(pr, dp[c][0]);
                int tmp = dp[c][1];
                dp[c][1] = mb>ps ? ps+1 : mb;
                ps = tmp;
                ans = std::max(ans, dp[c][1]);
            }
        }
        return ans*ans;
    }
};
