int evalRPN(char** tokens, int tokensSize) {
    int* st = (int*) malloc(sizeof(int) * tokensSize);
    int top = -1;
    int num;
    for (int p=0; p<tokensSize; p++) {
        char* token = tokens[p];
        char t0 = token[0];
        int tl = strlen(token);
        if (tl > 1 || isdigit(t0)) {
            st[++top] = atoi(token);
            continue;
        }
        num = st[top];
        if (t0 == '+') {
            st[--top] += num;
        } else if (t0 == '-') {
            st[--top] -= num;
        } else if (t0 == '*') {
            st[--top] *= num;
        } else if (t0 == '/') {
            st[--top] /= num;
        }
    }
    int res = st[0];
    free(st);
    return res;
}
