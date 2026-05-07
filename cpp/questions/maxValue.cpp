#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> pmax = nums;
        for (int p=1; p<n; ++p) {
            pmax[p] = std::max(pmax[p], pmax[p-1]);
        }
        std::vector<int> ans(n);
        int smin = INT_MAX;
        for (int p=n-1; p>=0; --p) {
            ans[p] = pmax[p]>smin ? ans[p+1] : pmax[p];
            smin = std::min(smin, nums[p]);
        }
        return ans;
    }
};
