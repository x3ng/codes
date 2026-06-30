#include <bits/stdc++.h>

using namespace std;

class MinStack {
private:
    std::stack<std::pair<int ,int>> st;
public:
    MinStack() {}
    
    void push(int value) {
        int cm = value;
        if (!st.empty()) {
            cm = std::min(cm, st.top().second);
        }
        st.emplace(value, cm);
    }
    
    void pop() {
        st.pop(); 
    }
    
    int top() {
        return st.top().first; 
    }
    
    int getMin() {
        return st.top().second; 
    }
};
