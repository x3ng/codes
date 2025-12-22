class Solution {
public:
    int evalRPN(vector<std::string>& tokens) {
        std::stack<int> st;
        char t0;
        int num;
        for (std::string& token : tokens) {
            t0 = token[0];
            if (token.size() > 1 || std::isdigit(t0)) {
                st.push(std::stoi(token));
                continue;
            }
            num = st.top();
            st.pop();
            if (t0 == '+') {
                st.top() += num;
            } else if (t0 == '-') {
                st.top() -= num;
            } else if (t0 == '*') {
                st.top() *= num;
            } else if (t0 == '/') {
                st.top() /= num;
            }
        }
        return st.top();
    }
};
