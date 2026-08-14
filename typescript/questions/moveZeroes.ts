function moveZeroes(nums: number[]): void {
  let nl = nums.length;
  let zp = 0;
  for (let i = 0; i < nl; ++i) {
    if (nums[i] != 0) {
      [nums[zp], nums[i]] = [nums[i], nums[zp]];
      ++zp;
    }
  }
}
