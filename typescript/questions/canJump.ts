function canJump(nums: number[]): boolean {
  let nl = nums.length;
  let mp = 0;
  for (let i = 0; i <= mp; ++i) {
    mp = Math.max(mp, i + nums[i]);
    if (mp >= nl - 1) {
      return true;
    }
  }
  return false;
}
