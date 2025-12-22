class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        std::stack<int> ops;
        ops.push(1);
        int sign = 1;
        int p = 0;
        char c;
        int num;
        while (p < s.size()) {
            c = s[p];
            if (c == ' ') {
                p++;
            } else if (c == '+') {
                sign = ops.top();
                p++;
            } else if (c == '-') {
                sign = -ops.top();
                p++;
            } else if (c == '(') {
                ops.push(sign);
                p++;
            } else if (c == ')') {
                ops.pop();
                p++;
            } else {
                num = 0;
                while (s[p] < '9' && s[p] > '0') {
                    num = num*10 + s[p] - '0';
                    p++;
                }
                ans += sign * num;
            }
        }
        return ans;
    }
};
