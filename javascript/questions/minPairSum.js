/**
 * @param {number[]} nums
 * @return {number}
 */
var minPairSum = function(nums) {
    nums.sort((a, b) => a - b);
    let l = 0;
    let r = nums.length - 1;
    let ans = -Infinity;
    while (l < r) {
        const cps = nums[l] + nums[r];
        if (ans < cps) {
            ans = cps;
        }
        l++;
        r--;
    }
    return ans;
};
