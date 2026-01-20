function minBitwiseArray(nums: number[]): number[] {
    let n = nums.length;
    const ans: number[] = new Array(n);
    for (let p=0; p<n; p++) {
	if (nums[p] === 2) {
	    ans[p] = -1;
	    continue;
	}
	const tmp = ~nums[p];
	ans[p] = nums[p] ^ ((tmp&-tmp)>>1);
    }
    return ans;
};
