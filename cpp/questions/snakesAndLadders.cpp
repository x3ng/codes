class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        std::vector<bool> vis(n*n+1, false);
        vis[1] = true;
        std::deque<int> sr{1};
        for (int step=0; !sr.empty(); step++) {
            int cl = sr.size();
            while (cl--) {
                int cn = sr.front();
                sr.pop_front();
                if (cn == n*n) {
                    return step;
                }
                for (int cs=cn+1; cs<=min(cn+6, n*n); cs++) {
                    int c = (cs - 1) / n;
                    int r = (cs - 1) % n;
                    if (c % 2 != 0) {
                        r = n - 1 - r;
                    }
                    int nxt = board[n-1-c][r];
                    if (nxt < 0) {
                        nxt = cs;
                    }
                    if (vis[nxt] == false) {
                        vis[nxt] = true;
                        sr.push_back(nxt);
                    }
                }
            }
        }
        return -1;
    }
};
