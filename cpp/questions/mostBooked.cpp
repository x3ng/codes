class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ranges::sort(meetings, {}, [](auto& m) { return m[0]; });
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> usingR;
        std::priority_queue<int, std::vector<int>, std::greater<>> freeR;
        std::vector<int> ans(n);
        for (int i=0; i<n; i++) {
            freeR.push(i);
        }
        for (auto& m : meetings) {
            while (!usingR.empty() && usingR.top().first<=m[0]) {
                freeR.push(usingR.top().second);
                usingR.pop();
            }
            int r;
            if (!freeR.empty()) {
                r = freeR.top();
                usingR.emplace(m[1], r);
                freeR.pop();
            } else {
                auto [e, rom] = usingR.top();
                usingR.pop();
                r = rom;
                usingR.emplace(m[1]+e-m[0], r);
            }
            ans[r]++;
        }
        return ranges::max_element(ans) - ans.begin();
    }
};
