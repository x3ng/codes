#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int ml = matrix.size();
    for (int r=0; r<ml/2; ++r) {
      for (int c=r; c<ml-1-r; ++c) {
        int tv = matrix[r][c];
        matrix[r][c] = matrix[ml-1-c][r];
        matrix[ml-1-c][r] = matrix[ml-1-r][ml-1-c];
        matrix[ml-1-r][ml-1-c] = matrix[c][ml-1-r];
        matrix[c][ml-1-r] = tv;
      }
    }
  }
};
