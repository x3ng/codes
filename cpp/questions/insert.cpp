class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      if (intervals.size() == 0) {
        return {newInterval};
      }
      std::vector<std::vector<int>> ans;
      bool flag = true;
      for (auto &p : intervals) {
        if (newInterval[0] > p[1]) {
          ans.emplace_back(p);
        } else if (newInterval[1] < p[0]) {
          if (flag) {
            ans.emplace_back(newInterval);
            flag = false;
          }
          ans.emplace_back(p);
        } else {
          newInterval[0] = std::min(p[0], newInterval[0]);
          newInterval[1] = std::max(p[1], newInterval[1]);
        }
      }
      if (flag) {
        ans.emplace_back(newInterval);
      }
      return ans;
    }
};
