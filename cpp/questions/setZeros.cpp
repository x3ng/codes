#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rs = matrix.size();
        int cs = matrix[0].size();
        bool r00 = false;
        for (int c=0; c<cs; ++c) {
            if (matrix[0][c] == 0) {
                r00 = true;
            }
        }
        for (int r=1; r<rs; ++r) {
            bool r0 = false;
            for (int c=0; c<cs; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    r0 = true;
                }
            }
            if (r0) {
                std::fill(matrix[r].begin(), matrix[r].end(), 0);
            }
        }
        for (int c=0; c<cs; ++c) {
            if (matrix[0][c] == 0) {
                for (int r=1; r<rs; ++r) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (r00) {
            std::fill(matrix[0].begin(), matrix[0].end(), 0);
        }
    }
};

