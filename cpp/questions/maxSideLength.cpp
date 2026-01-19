class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<std::vector<int>> prew(m+1, std::vector<int>(n+1, 0));
        int maxSide = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                prew[i+1][j+1] = prew[i][j+1] + prew[i+1][j] - prew[i][j] + mat[i][j];
                if (i>=maxSide && j>=maxSide) {
                    int cs = prew[i+1][j+1] - prew[i+1][j-maxSide] - prew[i-maxSide][j+1] + prew[i-maxSide][j-maxSide];
                    if (cs <= threshold) {
                        maxSide++;
                    }
                }
            }
        }
        return maxSide;
    }
};
