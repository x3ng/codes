#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int ws1 = word1.size();
        int ws2 = word2.size();
        std::vector<std::vector<int>> dp(ws1, std::vector<int>(ws2, -1));
        std::function<int(int, int)> dfs = [&](int p1, int p2) -> int {
            if (p1 < 0) {
                return p2+1;
            }
            if (p2 < 0) {
                return p1+1;
            }
            int& pc = dp[p1][p2];
            if (pc != -1) {
                return pc;
            }
            if (word1[p1] == word2[p2]) {
                pc = dfs(p1-1, p2-1);
                return pc;
            }
            pc = std::min({dfs(p1-1, p2), dfs(p1, p2-1), dfs(p1-1, p2-1)})+1;
            return pc;
        };
        return dfs(ws1-1, ws2-1);
    }
};
