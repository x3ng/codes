function reverse(nums: number[], l: number, r: number): void {
  while (l < r) {
    [nums[l], nums[r]] = [nums[r], nums[l]];
    ++l;
    --r;
  }
}

function rotate(nums: number[], k: number): void {
  const ns = nums.length;
  k %= ns;
  reverse(nums, 0, ns - 1);
  reverse(nums, 0, k - 1);
  reverse(nums, k, ns - 1);
}
