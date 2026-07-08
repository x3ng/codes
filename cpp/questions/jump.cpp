#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ns = nums.size();
        int ans = 0;
        int sp = 0;
        int ep = 0;
        while (ep < ns-1) {
            int ne = sp;
            for (int i=sp; i<ep+1; ++i) {
                ne = std::max(ne, i+nums[i]);
            }
            sp = ep + 1;
            ep = ne;
            ++ans;
        }
        return ans;
    }
};
