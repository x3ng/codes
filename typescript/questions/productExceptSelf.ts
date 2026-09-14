function productExceptSelf(nums: number[]): number[] {
  const nl = nums.length;
  let ans: number[] = new Array(nl);    
  ans[nl-1] = 1;
  for (let p=nl-2; p>=0; --p) {
    ans[p] = ans[p+1] * nums[p+1];
  }
  let pre = nums[0];
  for (let p=1; p<nl; ++p) {
    ans[p] *= pre;
    pre *= nums[p];
  }
  return ans;
};
