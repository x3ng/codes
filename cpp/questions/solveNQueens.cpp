#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> tmp(n, std::string(n, '.'));
        std::vector<bool> cp(n, false);
        std::vector<bool> ml(2*n-1, false);
        std::vector<bool> pl(2*n-1, false);
        std::function<void(int)> bt = [&](int r) -> void {
            if (r == n) {
                ans.emplace_back(tmp);
                return;
            }
            for (int c=0; c<n; ++c) {
                if (!cp[c] && !ml[r-c+n-1] && !pl[r+c]) {
                    tmp[r][c] = 'Q';
                    cp[c] = true;
                    ml[r-c+n-1] = true;
                    pl[r+c] = true;
                    bt(r+1);
                    cp[c] = false;
                    ml[r-c+n-1] = false;
                    pl[r+c] = false;
                    tmp[r][c] = '.';
                }
            }
        };
        bt(0);
        return ans;
    }
};
