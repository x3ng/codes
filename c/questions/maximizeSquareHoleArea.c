#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int getmc(int* Bars, int BarsSize) {
    qsort(Bars, BarsSize, sizeof(int), compare);
    int mc = 2;
    int cc = 2;
    int prev = Bars[0];
    int curr;
    for (int p=1; p<BarsSize; p++) {
        curr = Bars[p];
        if (curr == prev+1) {
            cc++;
        } else {
            mc = MAX(mc, cc);
            cc = 2;
        }
        prev = curr;
    }
    mc = MAX(mc, cc);
    return mc;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
    int mhc = getmc(hBars, hBarsSize);
    int mvc = getmc(vBars, vBarsSize);
    int mmc = MIN(mhc, mvc);
    return mmc * mmc;
}
