#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rs = matrix.size();
        int cs = matrix[0].size();
        int s = 0;
        int e = rs * cs - 1;
        while (s < e) {
            int m = (s + e) / 2;
            int v = matrix[m/cs][m%cs];
            if (v == target) {
                return true;
            } else if (v > target) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return matrix[s/cs][s%cs]==target;
    }
};
