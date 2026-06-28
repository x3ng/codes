#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] < nums[r]) {
            return nums[0];
        }
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] >= nums[l]) {
                if (nums[l] > nums[r]) {
                    l = m + 1;
                } else {
                    return nums[l];
                }
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};
