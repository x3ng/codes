#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        std::stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i=0; i<height.size(); ++i) {
            int ch = height[i];
            int sp = i - 1;
            while (st.top()!=-1 && ch>=height[st.top()]) {
                int ct = st.top();
                st.pop();
                ans += st.top()==-1 ? (i-ct-1)*(height[ct]-ch) : (sp-st.top())*(ch-height[ct]);
                sp = st.top();
            }
            st.push(i);
        }
        return ans;
    }
};
