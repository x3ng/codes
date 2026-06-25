#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        // if (nums[l] >= target) {
        //     return 0;
        // } else if (nums[r] == target) {
        //     return r;
        // } else if (nums[r] < target) {
        //     return nums.size();
        // }
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return nums[l]<target ? l+1 : l;
    }
};
