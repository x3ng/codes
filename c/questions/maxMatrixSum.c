#define min(a, b) ((a)<(b) ? (a) : (b))

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long ans = 0;
    int neg_cnt = 0;
    int mn = INT_MAX;
    int absn;
    for (int r=0; r<matrixSize; r++) {
        for (int c=0; c<*matrixColSize; c++) {
            if (matrix[r][c] <= 0) {
                absn = -matrix[r][c];
                neg_cnt += 1;
            } else {
                absn = matrix[r][c];
            }
            ans += absn;
            mn = min(mn, absn);
        }
    }
    if (neg_cnt%2 == 0) {
        return ans;
    } else {
        return ans-mn*2;
    }
}
