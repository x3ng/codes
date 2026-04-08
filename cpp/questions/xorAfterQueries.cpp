#include <vector>

using namespace std;

class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        for (const auto& q: queries) {
            for (int p=q[0]; p<=q[1]; p+=q[2]) {
                nums[p] = (static_cast<long long>(nums[p]) * q[3]) % MOD;
            }
        }
        for (const auto& n: nums) {
            ans ^= n;
        }
        return ans;
    }
};
