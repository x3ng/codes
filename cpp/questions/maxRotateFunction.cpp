#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sm = 0;
        int sc = 0;
        for (int p=0; p<n; ++p) {
            sc += p * nums[p];
            sm += nums[p];
        }
        int mx = sc;
        for (int p=0; p<n-1; ++p) {
            sc += n*nums[p] - sm;
            mx = std::max(mx, sc);
        }
        return mx;
    }
};
