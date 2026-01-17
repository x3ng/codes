#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {
    int maxSide = 0;
    for (int i=0; i<topRightSize; i++) {
        int ixs = topRight[i][0] - bottomLeft[i][0];
        int iys = topRight[i][1] - bottomLeft[i][1];
        if (maxSide >= MIN(ixs, iys)) {
            continue;
        }
        for (int j=i+1; j<topRightSize; j++) {
            int maxl = MAX(bottomLeft[i][0], bottomLeft[j][0]);
            int maxb = MAX(bottomLeft[i][1], bottomLeft[j][1]);
            int minr = MIN(topRight[i][0], topRight[j][0]);
            int minu = MIN(topRight[i][1], topRight[j][1]);
            int xs = minr - maxl;
            int ys = minu - maxb;
            int minss = MIN(xs, ys);
            maxSide = MAX(maxSide, minss);
        }
    }
    return 1LL * maxSide * maxSide;
}
