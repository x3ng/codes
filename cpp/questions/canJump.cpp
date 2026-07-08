#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ns = nums.size();
        int f = 0;
        for (int i=0; i<ns; ++i) {
            if (i <= f) {
                f = std::max(f, i+nums[i]);
                if (f >= ns-1) {
                    return true;
                }
            }
        }
        return false;
    }
};
