#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> ans(2, -1);
        int ns = nums.size();
        if (ns == 0) {
            return ans;
        }
        int l = 0;
        int r = ns;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (l>=ns || nums[l]!= target) {
            return ans;
        }
        ans[0] = l;
        r = ns - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        ans[1] = r;
        return ans;
    }
};
