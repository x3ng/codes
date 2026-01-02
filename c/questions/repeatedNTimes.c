int repeatedNTimes(int* nums, int numsSize) {
    int numcnt[10001];
    memset(numcnt, 0, sizeof(numcnt));
    int n = numsSize / 2;
    for (int p=0; p<numsSize; p++) {
        if (++numcnt[nums[p]] == n) {
            return nums[p];
        }
    }
    return -1;
}
