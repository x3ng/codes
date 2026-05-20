#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);    
        int pp = 1;
        for (int i=0; i<n; ++i) {
            ans[i] = pp;
            pp *= nums[i];
        }
        pp = 1;
        for (int i=n-1; i>=0; --i) {
            ans[i] *= pp;
            pp *= nums[i];
        }
        return ans;
    }
};
