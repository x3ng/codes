int bestClosingTime(char* customers) {
    int ans = 0;
    int p = 1;
    int minc = 0;
    int yc = 0;
    int nc = 0;
    while (*customers) {
        if (*customers == 'N') {
            nc++;
        } else {
            yc--;
        }
        if (minc > nc+yc) {
            minc = nc+yc;
            ans = p;
        }
        p++;
        customers++;
    }
    return ans;
}
