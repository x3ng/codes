#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r = 0;
        for (int p=0; p<nums.size(); ++p) {
            if (nums[p] != val) {
                nums[r++] = nums[p];
            }
        }
        return r;
    }
};
