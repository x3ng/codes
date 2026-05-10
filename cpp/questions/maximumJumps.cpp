#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> stat(n, -1);
        stat[0] = 0;
        for (int p=0; p<n; ++p) {
            if (stat[p] == -1) {
                continue;
            }
            for (int sp=p+1; sp<n; ++sp) {
                if (stat[sp]<=stat[p] && std::abs(nums[sp]-nums[p])<=target) {
                    stat[sp] = stat[p] + 1;
                }
            }
        }
        return stat.back();
    }
};
