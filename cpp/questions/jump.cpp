#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ns = nums.size();
        int r = 0;
        int l = 0;
        int s = 0;
        while (l <= r) {
            if (r >= ns-1) {
                return s;
            }
            int cr = r;
            for (; l<=cr; ++l) {
                r = std::max(r, nums[l]+l);
            }
            ++s;
        }
        return -1;
    }
};
