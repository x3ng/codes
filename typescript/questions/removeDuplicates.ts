function removeDuplicates(nums: number[]): number {
  let nl = nums.length;
  let vp = 0;
  for (let sp = 0; sp < nl; ++sp) {
    if (nums[sp] != nums[vp]) {
      nums[++vp] = nums[sp];
    }
  }
  return vp + 1;
}
