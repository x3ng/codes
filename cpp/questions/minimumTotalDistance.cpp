#include <vector>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int rs = robot.size();
        int fs = factory.size();
        std::sort(robot.begin(), robot.end(), std::less<>());
        std::sort(factory.begin(), factory.end(), [](auto& a, auto& b) -> bool { return a[0] < b[0]; });
        std::vector<std::vector<long long>> memo(rs, std::vector<long long>(fs, -1));

        std::function<long long(int, int)> dfs = [&](int ri, int fi) -> long long {
            if (ri == -1) {
                return 0;
            }
            if (fi == -1) {
                return LLONG_MAX / 2;
            }
            auto& mc = memo[ri][fi];
            if (mc == -1) {
                const auto& fp = factory[fi][0];
                const auto& fc = factory[fi][1];
                mc = dfs(ri, fi-1);
                long long ac = 0;
                for (int rp=ri; rp>=0 && ri-rp<=fc-1; --rp) {
                    ac += std::abs(fp - robot[rp]);
                    mc = std::min(mc, ac+dfs(rp-1, fi-1));
                }
            }
            return mc;
        };

        return dfs(rs-1, fs-1);
    }
};
