#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int find(const std::vector<int>& v, int x) {
        int l = 0;
        int r = v.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (v[m] == x) {
                return m;
            } else if (v[m] < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return v[l]==x ? l : -1;
    }
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int ns = nums.size();
        int qs = queries.size();
        std::unordered_map<int, std::vector<int>> hm;
        for (int p=0; p<ns; ++p) {
            hm[nums[p]].push_back(p);
        }
        for (auto& [_, h]: hm) {
            h.insert(h.begin(), h.back()-ns);
            h.push_back(h[1]+ns);
        }
        for (auto& q: queries) {
            const auto& cv = hm[nums[q]];
            if (cv.size() == 3) {
                q = -1;
                continue;
            }
            int p = find(cv, q);
            q = std::min(q-cv[p-1], cv[p+1]-q);
        }
        return queries;
    }
};
