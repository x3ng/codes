class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      ranges::sort(points, {}, [](auto& p){return p[1];});
      int ans = 0;
      long long pre = LLONG_MIN;
      for (auto& p : points) {
        if (p[0] > pre) {
          ans += 1;
          pre = p[1];
        }
      }
      return ans;
    }
};
