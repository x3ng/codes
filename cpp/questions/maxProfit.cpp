#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pm = prices[0];
        int ans = 0;
        for (const auto& p: prices) {
            ans = std::max(ans, p-pm);
            pm = std::min(pm, p);
        }
        return ans;
    }
};
