class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ps = points.size();
        int ans = 0;
        int px = points[0][0];
        int py = points[0][1];
        for (int p=1; p<ps; p++) {
            int cx = points[p][0];
            int cy = points[p][1];
            ans += std::max(std::abs(cx-px), std::abs(cy-py));
            px = cx;
            py = cy;
        }
        return ans;
    }
};
