#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);
        for (int p=0; p<n; p++) {
            int cp = (n + p + nums[p] % n) % n;
            ans[p] = nums[cp];
        }
        return ans;
    }
};
