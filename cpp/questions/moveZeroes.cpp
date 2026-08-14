#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zp = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]) {
                std::swap(nums[i], nums[zp++]);
            }
        }
    }
};
