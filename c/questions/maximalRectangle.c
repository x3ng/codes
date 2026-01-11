#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int rh[*matrixColSize];
    for (int p=0; p<*matrixColSize; p++) {
        rh[p] = 0;
    }
    int ans = 0;
    int* st = (int*) malloc(sizeof(int)*(*matrixColSize+1));
    int stt = -1;
    st[++stt] = -1;
    int nh;
    int na;
    for (int cr=0; cr<matrixSize; cr++) {
        for (int cc=0; cc<*matrixColSize; cc++) {
            if (matrix[cr][cc] == '1') {
                rh[cc] += 1;
            } else {
                rh[cc] = 0;
            }
            while (stt>0 && rh[st[stt]]>=rh[cc]) {
                nh = rh[st[stt--]];
                na = nh * (cc-st[stt]-1);
                ans = MAX(ans, na);
            }
            st[++stt] = cc;
        }
        while (stt>0 && rh[st[stt]]>=0) {
            nh = rh[st[stt--]];
            na = nh * (*matrixColSize-st[stt]-1);
            ans = MAX(ans, na);
        }
    }
    return ans;
}
