#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ns = nums.size();
        int mp = 0;
        for (int i=0; i<=mp; ++i) {
            mp = std::max(mp, i+nums[i]);
            if (mp >= ns-1) {
                return true;
            }
        }
        return false;
    }
};
