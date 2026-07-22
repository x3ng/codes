#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int v = 0;
        int s;
        for (const auto n: nums) {
            if (v == 0) {
                s = n;
                ++v;
            } else if (s == n) {
                ++v;
            } else {
                --v;
            }
        }
        return s;
    }
};
