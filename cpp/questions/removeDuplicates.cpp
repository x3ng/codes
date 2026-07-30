#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ns = nums.size();
        int vp = 0;
        for (const auto& n: nums) {
            if (n != nums[vp]) {
                nums[++vp] = n;
            }
        }
        return vp + 1;
    }
};
