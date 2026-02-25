class Solution {
public:
    int totalNQueens(int n) {
        std::vector<bool> column(n, false);
        std::vector<bool> x1(2*n-1, false);
        std::vector<bool> x2(2*n-1, false);
        int ans = 0;
        auto bt = [&](this auto&& bt, int r) -> void {
            if (r == n) {
                ans++;
            } else {
                for (int c=0; c<n; ++c) {
                    if (column[c]) {
                        continue;
                    }
                    if (x1[r-c+n-1]) {
                        continue;
                    }
                    if (x2[r+c]) {
                        continue;
                    }
                    column[c] = true;
                    x1[r-c+n-1] = true;
                    x2[r+c] = true;
                    bt(r+1);
                    column[c] = false;
                    x1[r-c+n-1] = false;
                    x2[r+c] = false;
                }
            }
        };
        bt(0);
        return ans;
    }
};
