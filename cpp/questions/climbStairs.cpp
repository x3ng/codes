#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    std::vector<int> cc;
public:
    int climbStairs(int n) {
        if (cc.size() < n+1) {
            cc.resize(n+1, -1);
        }
        if (cc[n] == -1) {
            if (n <= 1) {
                cc[n] = 1;
            } else {
                cc[n] = climbStairs(n-1) + climbStairs(n-2);
            }
        }
        return cc[n];
    }
};
