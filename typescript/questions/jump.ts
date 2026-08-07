function jump(nums: number[]): number {
  let nl = nums.length;
  let l = 0;
  let r = 0;
  let s = 0;
  while (l <= r) {
    if (r >= nl - 1) {
      return s;
    }
    let cr = r;
    for (; l <= cr; ++l) {
      r = Math.max(r, nums[l] + l);
    }
    ++s;
  }
  return -1;
}
