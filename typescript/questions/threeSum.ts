function threeSum(nums: number[]): number[][] {
  let nl = nums.length;
  const ans: number[][] = [];
  nums.sort((a, b) => a - b);
  let e2 = nums[nl - 1] + nums[nl - 2];
  for (let i = 0; i < nl - 2; ++i) {
    if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
      break;
    }
    if ((i > 0 && nums[i] == nums[i - 1]) || nums[i] + e2 < 0) {
      continue;
    }
    let l = i + 1;
    let r = nl - 1;
    while (l < r) {
      let s = nums[i] + nums[l] + nums[r];
      if (s > 0) {
        --r;
      } else if (s < 0) {
        ++l;
      } else {
        ans.push([nums[i], nums[l], nums[r]]);
        do {
          ++l;
        } while (l < r && nums[l] == nums[l - 1]);
        do {
          --r;
        } while (l < r && nums[r] == nums[r + 1]);
      }
    }
  }
  return ans;
}
