int cmp(const void *a, const void *b) {
  int *A = *(int **) a;
  int *B = *(int **) b;
  return A[0]-B[0]; 
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
  int** ans = (int**) malloc(intervalsSize*sizeof(int*));
  *returnColumnSizes = malloc(intervalsSize*sizeof(int*));

  for (int i=0; i<intervalsSize; i++) {
    ans[i] = (int*) malloc(2*sizeof(int));
    (*returnColumnSizes)[i] = 2;
  }

  int count = 0;
  qsort(intervals, intervalsSize, sizeof(int*), cmp);

  for (int i=0; i<intervalsSize; i++) {
    int l = intervals[i][0];
    int r = intervals[i][1];
    if (count==0 || l>ans[count-1][1]) {
      ans[count][0] = l;
      ans[count][1] = r;
      count++;
    } else {
      ans[count-1][1] = fmax(ans[count-1][1], r);
    }
  }

  *returnSize = count;
  return ans;
}
