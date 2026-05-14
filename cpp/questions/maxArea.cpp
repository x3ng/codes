#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        while (l < r) {
            bool rbl = height[r] > height[l];
            int minh = rbl ? height[l] : height[r];
            ans = std::max(ans, (r-l)*minh);
            r -= rbl ? 0 : 1;
            l += rbl ? 1 : 0;
        }
        return ans;
    }
};
