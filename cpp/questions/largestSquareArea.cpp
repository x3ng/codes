class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxSide = 0;
        for (int i=0; i<n; i++) {
            if (maxSide >= std::min(topRight[i][0]-bottomLeft[i][0], topRight[i][1]-bottomLeft[i][1])) {
                continue;
            }
            for (int j=i+1; j<n; j++) {
                int x = std::min(topRight[j][0], topRight[i][0]) - std::max(bottomLeft[j][0], bottomLeft[i][0]);
                int y = std::min(topRight[j][1], topRight[i][1]) - std::max(bottomLeft[j][1], bottomLeft[i][1]);
                maxSide = std::max(maxSide, std::min(x, y));
            }
        }
        return 1LL* maxSide * maxSide;
    }
};
