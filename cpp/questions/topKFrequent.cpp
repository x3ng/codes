#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> hm;
        for (const auto& n: nums) {
            hm[n]++;
        }
        struct cmp {
            bool operator()(const std::pair<int, int>& a, const std::pair<int ,int>& b) const {
                return a.first > b.first;
            }
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> pq;
        for (auto it=hm.begin(); it!=hm.end(); ++it) {
            auto [n, c] = *it;
            if (pq.size() < k) {
                pq.emplace(c, n);
            } else if (c > pq.top().first) {
                pq.pop();
                pq.emplace(c, n);
            }
        }
        std::vector<int> ans;
        ans.reserve(k);
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
