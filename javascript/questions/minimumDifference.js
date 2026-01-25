/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimumDifference = function(nums, k) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let ans = Infinity;
    for (let p=k-1; p<n; p++) {
        const curr_diff = nums[p] - nums[p-k+1];
        ans = Math.min(ans, curr_diff);
    }
    return ans;
};
