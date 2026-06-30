#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    std::unordered_map<char, char> hm = {{')', '('}, {']', '['}, {'}', '{'}};
public:
    bool isValid(string s) {
        std::stack<char> st;
        st.push(0);
        for (const auto& c: s) {
            if (c=='(' || c=='[' || c=='{') {
                st.push(c);
            } else {
                if (st.top() == hm[c]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.top()==0;
    }
};
