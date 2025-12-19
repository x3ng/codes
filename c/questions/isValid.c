bool isValid(char* s) {
  char mp[128];
  mp['('] = ')';
  mp['['] = ']';
  mp['{'] = '}';
  int top = 0;
  for (int p=0; s[p]; p++) {
    if (mp[s[p]]) {
      s[top++] = s[p];
    } else {
      if (top==0 || mp[s[--top]]!=s[p]) {
        return 0;
      }
    }
  }
  return top == 0;
}
