#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        std::vector<long long> ps;
        ps.reserve(n);
        for (const auto& v: points) {
            const auto& x = v[0];
            const auto& y = v[1];
            long long pv = 0;
            if (x == 0) {
                pv = y;
            } else if (y == side) {
                pv = side + x;
            } else if (x == side) {
                pv = side * 3LL - y;
            } else {
                pv = side * 4LL - x;
            }
            ps.emplace_back(pv);
        }
        std::sort(ps.begin(), ps.end(), std::less<>());
        std::function<bool(int)> fr = [&](int ds) -> bool {
            std::vector<int> cp(k, 0);
            while (1) {
                for (int i=1; i<k; ++i) {
                    const auto& pv = ps[cp[i-1]];
                    auto& cpi = cp[i];
                    while (ps[cpi]-pv < ds) {
                        ++cpi;
                        if (cpi == n) {
                            return false;
                        }
                    }
                }
                if (ps[cp.back()]-ps[cp[0]] <= side*4LL-ds) {
                    return true;
                }
                ++cp[0];
            }
            return false;
        };
        int l = 1;
        int r = 4LL * side / k + 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (fr(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return fr(l) ? l : l-1;
    }
};
