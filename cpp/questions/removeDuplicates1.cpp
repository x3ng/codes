#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ns = nums.size();
        int vp = 0;
        int sp = 1;
        while (sp < ns) {
            int vv  = nums[vp];
            nums[++vp] = nums[sp];
            if (nums[sp] != vv) {
                sp++;
            } else {
                while (sp<ns && nums[sp]==vv) {
                    sp++;
                }
            }
        }
        return vp+1;
    }
};
