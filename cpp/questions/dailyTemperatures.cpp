#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int ts = temperatures.size();
        std::vector<int> ans(ts, 0);
        std::stack<std::pair<int, int>> st;
        for (int p=0; p<ts; ++p) {
            const int ct = temperatures[p];
            while (!st.empty() && ct>st.top().first) {
                ans[st.top().second] = p - st.top().second;
                st.pop();
            }
            st.emplace(ct, p);
        }
        return ans;
    }
};
