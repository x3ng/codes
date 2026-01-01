/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int p;
    for (p=digitsSize-1; p>=0; p--) {
        if (digits[p] < 9) {
            digits[p]++;
            *returnSize = digitsSize;
            int* ans = (int*) malloc(sizeof(int)*(*returnSize));
            for (int p=0; p<*returnSize; p++) {
                ans[p] = digits[p];
            }
            return ans;
        } else {
            digits[p] = 0;
        }
    }
    *returnSize = digitsSize + 1;
    int* ans = (int*) malloc(sizeof(int)*(*returnSize));
    ans[0] = 1;
    for (int p=1; p<*returnSize; p++) {
        ans[p] = 0;
    }
    return ans;
}
