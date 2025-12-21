class MinStack {
    std::stack<std::pair<int, int>> st;
public:
    MinStack() {
        st.emplace(0, INT_MAX);
    }
    
    void push(int val) {
        st.emplace(val, std::min(val, getMin()));
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
