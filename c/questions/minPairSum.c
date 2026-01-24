#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmp(const void* a, const void* b) {
    int av = *(int*)a;
    int bv = *(int*)b;
    return av < bv ? -1 : 1;
}

int minPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int l = 0;
    int r = numsSize - 1;
    int ans = INT_MIN;
    while (l < r) {
        int cps = nums[l] + nums[r];
        ans = MAX(ans, cps);
        l++;
        r--;
    }
    return ans;
}
