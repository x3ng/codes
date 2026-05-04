#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0;
        for (int l=0; l<n/2; ++l) {
            for (int p=l; p<n-1-l; ++p) {
                int tmp = matrix[l][p];
                matrix[l][p] = matrix[n-1-p][l];
                matrix[n-1-p][l] = matrix[n-1-l][n-1-p];
                matrix[n-1-l][n-1-p] = matrix[p][n-1-l];
                matrix[p][n-1-l] = tmp;
            }
        }
    }
};
