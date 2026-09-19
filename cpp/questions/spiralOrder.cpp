#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static constexpr int DIR[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int cs = matrix[0].size();
        int ns = matrix.size() - 1;
        std::vector<int> ans(matrix.size() * matrix[0].size());
        int d = 0;
        int r = 0;
        int c = -1;
        int p = 0;
        while (cs) {
            for (int i= 0; i<cs; ++i) {
                r += DIR[d][0];
                c += DIR[d][1];
                ans[p++] = matrix[r][c];
            }
            std::swap(cs, ns);
            --ns;
            d = (d + 1) % 4;
        }
        return ans;
    }
};
