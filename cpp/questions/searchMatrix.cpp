class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int rs = matrix.size();
        int cs = matrix[0].size();
        int r = rs * cs - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int dif = matrix[m/cs][m%cs] - target;
            if (dif == 0) {
                return true;
            } else if (dif > 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return matrix[l/cs][l%cs]==target;
    }
};
