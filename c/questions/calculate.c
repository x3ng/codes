int calculate(char* s) {
    int n = strlen(s);
    int ans = 0;
    int ops[n/2];
    ops[0] = 1;
    int top = 0;
    int sign = 1;
    int nums;
    char c;
    for (int p=0; p<n; ) {
        c = s[p];
        if (c == ' ') {
            p++;
        } else if (c == '+') {
            sign = ops[top];
            p++;
        } else if (c == '-') {
            sign = -ops[top];
            p++;
        } else if (c == '(') {
            ops[++top] = sign;
            p++;
        } else if (c == ')') {
            top--;
            p++;
        } else {
            nums = 0;
            while (p<n && s[p]<='9' && s[p]>='0') {
                nums = nums*10 + s[p] - '0';
                p++;
            }
            ans += sign * nums;
        }
    }
    return ans;
}
