char** split(const char* s, char delim, int* returnSize) {
  int n = strlen(s);
  char** ans = (char**) malloc(sizeof(char*) * n);
  int pos = 0;
  int cur = 0;
  int len = 0;

  while (pos < n) {
    while (pos < n && s[pos] == delim) {
      pos++;
    }
    cur = pos;
    while (pos <n && s[pos] != delim) {
      pos++;
    }
    if (cur < n) {
      ans[len] = (char*) malloc(sizeof(char) * (pos-cur+1));
      strncpy(ans[len], s+cur, pos-cur);
      ans[len][pos-cur] = '\0';
      len++;
    }
  }
  *returnSize = len;
  return ans;
}

char* simplifyPath(char* path) {
  int spSize = 0;
  int n = strlen(path);
  char** sps = split(path, '/', &spSize);
  char** stk = (char**) malloc(sizeof(char*) * spSize);
  int stkSize = 0;
  for (int p=0; p<spSize; p++) {
    if (!strcmp(sps[p], "") || !strcmp(sps[p], ".")) {
      continue;
    } else if (strcmp(sps[p], "..")) {
      stk[stkSize] = sps[p];
      stkSize++;
    } else if (stkSize) {
      stkSize--;
    }
  }
  char* ans = (char*) malloc(sizeof(char) * (n+1));
  int cur = 0;
  if (stkSize == 0) {
    ans[cur] = '/';
    cur++;
  } else {
    for (int p=0; p<stkSize; p++) {
      ans[cur] = '/';
      cur++;
      strcpy(ans+cur, stk[p]);
      cur += strlen(stk[p]);
    }
  }
  ans[cur] = '\0';
  for (int i=0; i<spSize; i++) {
    free(sps[i]);
  }
  free(sps);
  free(stk);
  return ans;
}
