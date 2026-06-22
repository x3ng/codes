#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rs = board.size();
        int cs = board[0].size();
        std::vector<std::vector<bool>> fg(rs, std::vector<bool>(cs, false));
        std::function<bool(int, int, int)> fw = [&](int r, int c, int p) -> bool {
            if (r<0 || r>=rs || c<0 || c>=cs || fg[r][c] || board[r][c]!=word[p]) {
                return false;
            }
            if (p == word.size()-1) {
                return true;
            }
            fg[r][c] = true;
            for (auto [dr, dc]: DIRS) {
                if (fw(r+dr, c+dc, p+1)) {
                    return true;
                }
            }
            fg[r][c] = false;
            return false;
        };
        for (int r=0; r<rs; ++r) {
            for (int c=0; c<cs; ++c) {
                if (fw(r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
