#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
        int p2 = 0;
        int s1 = nums1.size();
        int s2 = nums2.size();
        int fs = s1 + s2;
        int hs = (s1 + s2 + 1) / 2;
        int sn = hs + 1;
        while (sn > 1) {
            if (p1 == s1) {
                p2 = hs - s1;
                break;
            } else if (p2 == s2) {
                p1 = hs - s2;
                break;
            }
            int cp = sn >> 1;
            int n1 = p1 + cp;
            int n2 = p2 + cp;
            n1 = min(n1, s1);
            n2 = min(n2, s2);
            if (nums1[n1-1] > nums2[n2-1]) {
                p2 = n2;
            } else {
                p1 = n1;
            }
            sn -= cp;
        }
        int l1 = p1>0 ? nums1[p1-1] : INT_MIN;
        int l2 = p2>0 ? nums2[p2-1] : INT_MIN;
        int r1 = p1<s1 ? nums1[p1] : INT_MAX;
        int r2 = p2<s2 ? nums2[p2] : INT_MAX;
        if (fs % 2) {
            return max(l1, l2);
        } else {
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
    }
};
