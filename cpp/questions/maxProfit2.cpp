#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        for (int p=1; p<prices.size(); ++p) {
            const int cp = prices[p] - prices[p-1];
            mp += cp>0 ? cp : 0;
        }
        return mp;
    }
};
