#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ns = nums.size();
        int l = 0;
        int r = ns - 1;
        int p = l;
        while (p <= r) {
            if (nums[p] == 0) {
                std::swap(nums[p], nums[l]);
                while (l<ns && nums[l]==0) {
                    ++l;
                }
                p = std::max(l, p);
            } else if (nums[p] == 2) {
                std::swap(nums[p], nums[r]);
                while (r>=0 && nums[r]==2) {
                    --r;
                }
            }
            p += p<ns && nums[p]==1 ? 1 : 0;
        }
    }
};
