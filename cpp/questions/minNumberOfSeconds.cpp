#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int mt = *std::max_element(workerTimes.begin(), workerTimes.end());        
        long long l = 1;
        long long r = static_cast<long long>(mt) * (1 + mountainHeight) * mountainHeight / 2;
        std::function<bool(long long)> check = [&](long long lb) -> bool {
            long long aws = 0;
            for (const auto& wt: workerTimes) {
                long long ws = (-1.0 + std::sqrt(1 + 8 * (lb / wt))) / 2 + 1e-7;
                aws += ws;
                if (aws >= mountainHeight) {
                    return true;
                }
            }
            return false;
        };
        while (l < r) {
            long long m = (l + r) / 2;
            if (check(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return check(l) ? l : l+1;
    }
};
