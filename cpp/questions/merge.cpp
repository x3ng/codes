std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
  ranges::sort(intervals.begin(), intervals.ens());
  std::vector<std::vector<int>> ans;

  for (auto& p : intervals) {
    if (!ans.empty() && p[0] < ans.back()[1]) {
      ans.back()[1] = std::max(p[1], ans.back()[1]);
    } else {
      ans.emplace_back(p);
    }
  }
  return ans;
}
