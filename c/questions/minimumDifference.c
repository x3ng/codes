int cmp(const void* a, const void* b) {
    int av = *(int*)a;
    int bv = *(int*)b;
    if (av < bv) return -1;
    if (bv < av) return 1;
    return 0;
}

int minimumDifference(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = INT_MAX;
    for (int p=k-1; p<numsSize; p++) {
        int curr_diff = nums[p] - nums[p-k+1];
        if (curr_diff < ans) {
            ans = curr_diff;
        }
    }
    return ans;
}
