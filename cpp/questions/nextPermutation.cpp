#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int fb(std::vector<int>& v, int l, int r, int t) {
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (v[m] > t) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int ns = nums.size();
        int p = ns - 1;
        for (; p>0; --p) {
            if (nums[p] > nums[p-1]) {
                break;
            }
        }
        if (p != 0) {
            int bp = fb(nums, p, ns-1, nums[p-1]);
            std::swap(nums[p-1], nums[bp]);
        }
        int s = p;
        int e = ns - 1;
        while (s < e) {
            std::swap(nums[s++], nums[e--]);
        }
    }
};
