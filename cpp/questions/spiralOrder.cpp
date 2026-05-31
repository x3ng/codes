#include <vector>

using namespace std;

class Solution {
private:
    static constexpr int DIR[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs = matrix.size();
        int cs = matrix[0].size();
        std::vector<int> ans(rs*cs);
        int l = 0;
        int ac = 0;
        int d = 0;
        int r = 0;
        int c = 0;
        while (ac < rs*cs) {
            ans[ac++] = matrix[r][c];
            switch (d) {
                case 0:
                    if (c == cs-l-1) {
                        d = 1;
                    }
                    break;
                case 1:
                    if (r == rs-l-1) {
                        d = 2;
                    }
                    break;
                case 2:
                    if (c == l) {
                        d = 3;
                    }
                    break;
                case 3:
                    if (r == l+1) {
                        d = 0;
                        l += 1;
                    }
                    break;
            }
            r += DIR[d][0];
            c += DIR[d][1];
        }
        return ans;
    }
};
