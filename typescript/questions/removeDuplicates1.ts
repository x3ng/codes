function removeDuplicates(nums: number[]): number {
  let nl = nums.length;
  let vp = 0;
  let sp = 1;
  while (sp < nl) {
    let vv = nums[vp];
    nums[++vp] = nums[sp];
    if (nums[sp] != vv) {
      sp++;
    } else {
      while (sp < nl && nums[sp] == vv) {
        sp++;
      }
    }
  }
  return vp + 1;
}
