class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rs = board.size();
        int cs = board[0].size();
        auto bt = [&](this auto&& bt, int ri, int ci, int p) -> bool {
            char c = board[ri][ci];
            if (c == word[p]) {
                if (p == word.size()-1) {
                    return true;
                }
                board[ri][ci] = '#';
                for (auto& [dr, dc]: dir) {
                    int nr = ri + dr;
                    int nc = ci + dc;
                    if (nr>=0 && nr<rs && nc>=0 && nc<cs && board[nr][nc]!='#' && bt(nr, nc, p+1)) {
                        return true; 
                    }
                }
                board[ri][ci] = c;
            }
            return false;
        };
        for (int r=0; r<rs; ++r) {
            for (int c=0; c<cs; ++c) {
                if (bt(r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
