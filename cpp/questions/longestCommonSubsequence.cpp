#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        std::vector<std::vector<int>> memo(s1, std::vector<int>(s2, -1));
        std::function<int(int, int)> dfs = [&](int p1, int p2) -> int {
            if (p1<0 || p2<0) {
                return 0;
            }
            int& res = memo[p1][p2];
            if (res != -1) {
                return res;
            }
            if (text1[p1] == text2[p2]) {
                return res = 1+dfs(p1-1, p2-1);
            } else {
                return res = std::max(dfs(p1-1, p2), dfs(p1, p2-1));
            }
        };
        return dfs(s1-1, s2-1);
    }
};
