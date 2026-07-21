#include <bits/stdc++.h>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> r(n, 1);
        while (--m) {
            for (int i=1; i<n; ++i) {
                r[i] += r[i-1];
            }
        }
        return r[n-1];
    }
};
