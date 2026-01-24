function minPairSum(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let l = 0;
    let r = nums.length - 1;
    let ans = nums[l] + nums[r];
    l++;
    r--;
    while (l < r) {
        const cps = nums[l] + nums[r];
        if (cps > ans) {
            ans = cps;
        }
        l++;
        r--;
    }
    return ans;
};
