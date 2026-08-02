function rt(nums: number[], l: number, r: number): void {
  while (l < r) {
    [nums[l], nums[r]] = [nums[r], nums[l]];
    ++l;
    --r;
  }
}

function rotate(nums: number[], k: number): void {
  let ns = nums.length;
  k %= ns;
  rt(nums, 0, ns - 1);
  rt(nums, 0, k - 1);
  rt(nums, k, ns - 1);
}
