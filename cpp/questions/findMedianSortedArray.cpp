#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ns1 = nums1.size();
        int ns2 = nums2.size();
        if (ns1 > ns2) {
            std::swap(nums1, nums2);
            std::swap(ns1, ns2);
        }
        int tn = ns1 + ns2;
        int ts = tn / 2;
        int l = 0;
        int r = ns1;
        while (l <= r) {
            int m = (l + r) / 2;
            int tm = ts - m;
            int nums1l = m > 0 ? nums1[m-1] : INT_MIN;
            int nums1h = m < ns1 ? nums1[m] : INT_MAX;
            int nums2l = tm > 0 ? nums2[tm-1] : INT_MIN;
            int nums2h = tm < ns2 ? nums2[tm] : INT_MAX;
            if (nums1l <= nums2h && nums2l <= nums1h) {
                if (tn % 2) {
                    return std::min(nums1h, nums2h);
                } else {
                    return (std::max(nums1l, nums2l) + std::min(nums1h, nums2h)) / 2.0;
                }
            } else if (nums1h < nums2l) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return 0;
    }
};
