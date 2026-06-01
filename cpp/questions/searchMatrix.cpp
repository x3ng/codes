#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rs = matrix.size();
        int cs = matrix[0].size();
        int r = 0;
        int c = cs - 1;
        while(r<rs && c>=0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                --c;
            } else if (matrix[r][c] < target) {
                ++r;
            }
        }
        return false;
    }
};
