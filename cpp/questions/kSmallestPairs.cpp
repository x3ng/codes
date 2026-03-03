#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ns1 = nums1.size();
        int ns2 = nums2.size();
        std::vector<std::vector<int>> ans;
        ans.reserve(k);
        std::unordered_set<long long> vis;
        auto comp = [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[2] > b[2];
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> ppq(comp);
        ppq.push({0, 0, nums1[0]+nums2[0]});
        vis.insert(0);
        while (k--) {
            auto& cl = ppq.top();
            int p1 = cl[0];
            int p2 = cl[1];
            ans.emplace_back(std::vector<int>{nums1[p1], nums2[p2]});
            int p1n = p1 + 1;
            long long p1k = (static_cast<long long>(p1n)<<32) + p2;
            if (p1n < ns1 && !vis.count(p1k)) {
                ppq.push({p1n, p2, nums1[p1n]+nums2[p2]});
                vis.insert(p1k);
            }
            int p2n = p2 + 1;
            long long p2k = (static_cast<long long>(p1)<<32) + p2n;
            if (p2n < ns2 && !vis.count(p2k)) {
                ppq.push({p1, p2+1, nums1[p1]+nums2[p2+1]});
                vis.insert(p2k);
            }
            ppq.pop();
        }
        return ans;
    }
};
