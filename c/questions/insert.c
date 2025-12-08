int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
  int **ans = (int **)malloc(sizeof(int *) * (intervalsSize+1));
  *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize+1));
  int index = 0;
  int i;
  for (i=0; i<intervalsSize+1; i++) {
    (*returnColumnSizes)[i] = 2;
  }
  i = 0;
  while (i<intervalsSize && intervals[i][1]<newInterval[0]) {
    ans[index++] = intervals[i];
    i++;
  }
  if (i<intervalsSize) {
    newInterval[0] = fmin(newInterval[0], intervals[i][0]);
  }
  while (i<intervalsSize && intervals[i][0]<=newInterval[1]) {
    newInterval[1] = fmax(newInterval[1], intervals[i][1]);
    i++;
  }
  ans[index++] = newInterval;
  while (i<intervalsSize) {
    ans[index++] = intervals[i];
    i++;
  }
  *returnSize = index;
  return ans;
}
