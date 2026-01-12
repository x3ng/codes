#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int ans = 0;
    int px = points[0][0];
    int py = points[0][1];
    for (int p=1; p<pointsSize; p++) {
        int cx = points[p][0];
        int cy = points[p][1];
        int xb = abs(cx-px);
        int yb = abs(cy-py);
        ans += MAX(xb, yb);
        px = cx;
        py = cy;
    }
    return ans;
}
