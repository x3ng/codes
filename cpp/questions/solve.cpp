class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int cl = board.size();
        int rl = board[0].size();
        auto markarea = [&](this auto&& markarea, int c, int r) -> void {
            board[c][r] = 'M';
            if (c>0 && board[c-1][r]=='O') {
                markarea(c-1, r);
            }
            if (c<cl-1 && board[c+1][r]=='O') {
                markarea(c+1, r);
            }
            if (r>0 && board[c][r-1]=='O') {
                markarea(c, r-1);
            }
            if (r<rl-1 && board[c][r+1]=='O') {
                markarea(c, r+1);
            }
        };
        for (int p=0; p<rl; p++) {
            if (board[0][p] == 'O') {
                markarea(0, p);
            }
            if (board[cl-1][p] == 'O') {
                markarea(cl-1, p);
            }
        }
        for (int p=1; p<cl; p++) {
            if (board[p][0] == 'O') {
                markarea(p, 0);
            }
            if (board[p][rl-1] == 'O') {
                markarea(p, rl-1);
            }
        }
        for (int cp=0; cp<cl; cp++) {
            for (int rp=0; rp<rl; rp++) {
                if (board[cp][rp] == 'M') {
                    board[cp][rp] = 'O';
                } else {
                    board[cp][rp] = 'X';
                }
            }
        }
    }
};
