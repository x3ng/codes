int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int maxSide = 0;
    int** prew = (int**)malloc(sizeof(int*) * (matSize+1));
    int** cp = prew;
    for (int p=0; p<matSize+1; p++) {
        prew[p] = (int*)malloc(sizeof(int) * (*matColSize+1));
        prew[p][0] = 0;
    }
    memset(prew[0], 0, sizeof(int) * (*matColSize+1));
    for (int i=0; i<matSize; i++) {
        for (int j=0; j<*matColSize; j++) {
            prew[i+1][j+1] = prew[i][j+1] + prew[i+1][j] - prew[i][j] + mat[i][j];
            if (i>=maxSide && j>=maxSide) {
                int cs = prew[i+1][j+1] - prew[i+1][j-maxSide] - prew[i-maxSide][j+1] + prew[i-maxSide][j-maxSide];
                if (cs <= threshold) {
                    maxSide++;
                }
            }
        }
    }
    for (int p=0; p<matSize+1; p++) {
        free(prew[p]);
    }
    free(prew);
    return maxSide;
}
