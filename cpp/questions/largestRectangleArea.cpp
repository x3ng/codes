#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int hs = heights.size();
        int ans = 0;
        std::stack<int> st;
        st.push(-1);
        for (int p=0; p<hs; ++p) {
            int ch = heights[p];
            while (st.size()>1 && ch<=heights[st.top()]) {
                int ph = heights[st.top()];
                st.pop();
                ans = std::max(ans, ph*(p-st.top()-1));
            }
            st.push(p);
        }
        while (st.size() > 1) {
            int ph = heights[st.top()];
            st.pop();
            ans = std::max(ans, ph*(hs-st.top()-1));
        }
        return ans;
    }
};
