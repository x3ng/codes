/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for (int p=0; p<numsSize; p++) {
        if (nums[p] == 2) {
            ans[p] = -1;
            continue;
        }
        int tmp = ~nums[p];
        ans[p] = nums[p] ^ ((tmp&-tmp)>>1);
    }
    return ans;
}
