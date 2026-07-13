#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ns = nums.size();
        int ans = 0;
        std::vector<int> ep(ns, 0);
        for (const auto n: nums) {
            int l = 0;
            int r = ans;
            while (l < r) {
                int m = (l + r) / 2;
                if (ep[m] >= n) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            ep[l] = n;
            ans = std::max(ans, l+1);
        }
        return ans;        
    }
};
