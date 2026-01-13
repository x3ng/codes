bool check(double ylim, int** squares, int squaresSize, double totalArea) {
    double ca = 0;
    for (int p=0; p<squaresSize; p++) {
        int cy = squares[p][1];
        int cl = squares[p][2];
        if (cy < ylim) {
            ca += (double)cl * fmin((ylim-cy), cl);
        }
    }
    return ca*2 >= totalArea;
}
    
double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double ta = 0;
    double maxy = 0;
    for (int p=0; p<squaresSize; p++) {
        int cy = squares[p][1];
        int cl = squares[p][2];
        ta += (double)cl * cl;
        if (cy+cl > maxy) {
            maxy = cy+cl;
        }
    }
    double yu = maxy;
    double yd = 0;
    double mid;
    double eps = 1e-5;
    while (eps < yu-yd) {
        mid = (yu+yd) / 2;
        if (check(mid, squares, squaresSize, ta)) {
            yu = mid;
        } else {
            yd = mid;
        }
    }
    return (yu+yd)/2;
}
