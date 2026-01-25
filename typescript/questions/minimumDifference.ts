function minimumDifference(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = Infinity;
    for (let p=k-1; p<nums.length; p++) {
        const curr_diff = nums[p] - nums[p-k+1];
        ans = Math.min(ans, curr_diff);
    }
    return ans;
};
