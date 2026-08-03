#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mv = prices[0];
        int mp = 0;
        for (const auto& p: prices) {
            mv = min(mv, p);
            mp = max(mp, p-mv);
        }
        return mp;
    }
};
