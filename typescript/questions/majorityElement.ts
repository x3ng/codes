function majorityElement(nums: number[]): number {
  let v = 0;
  let p = 0;
  for (const n of nums) {
    if (v == 0) {
      p = n;
      v = 1;
    } else {
      v += n == p ? 1 : -1;
    }
  }
  return p;
}
