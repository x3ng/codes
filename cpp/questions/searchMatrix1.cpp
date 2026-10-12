#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mr = matrix.size();
        int mc = matrix[0].size();
        int r = 0;
        int c = mc - 1;
        while (r<mr && c>=0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                c -= 1;
            } else {
                r += 1;
            }
        }
        return false;
    }
};
