#include <stdlib.h>
#include <limits.h>

int cmp(const void* a, const void* b) {
  int ae = (*(int**)a)[1];
  int be = (*(int**)b)[1];
  return (ae > be) - (ae < be);
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
  qsort(points, pointsSize, sizeof(int*), cmp);
  int ans = 0;
  int pre = INT_MIN;
  for (int p=0; p<pointsSize; p++) {
    if (points[p][0] > pre) {
      ans++;
      pre = points[p][1];
    }
  }
  return ans;
}
