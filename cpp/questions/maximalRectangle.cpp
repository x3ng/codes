class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rs = matrix.size();
        int cs = matrix[0].size();
        int ans = 0;
        std::stack<int> st;
        st.push(-1);
        std::vector<int> rh(cs);
        for (int cr=0; cr<rs; cr++) {
            const auto& ch = matrix[cr];
            for (int cc=0; cc<cs; cc++) {
                if (ch[cc] == '1') {
                    rh[cc] += 1;
                } else {
                    rh[cc] = 0;
                }
                while (st.size()>1 && rh[st.top()]>=rh[cc]) {
                    int h = rh[st.top()];
                    st.pop();
                    ans = std::max(ans, h*(cc-st.top()-1));
                }
                st.push(cc);
            }
            while (st.size()>1 && rh[st.top()]>=0) {
                int h = rh[st.top()];
                st.pop();
                ans = std::max(ans, h*(cs-st.top()-1));
            }
        }
        return ans;
    }
};
