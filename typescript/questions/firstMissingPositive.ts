function firstMissingPositive(nums: number[]): number {
  const nl = nums.length;
  for (let i=0; i<nums.length; ++i) {
    while (nums[i]>0 && nums[i]<=nl && nums[nums[i]-1]!=nums[i] ) {
      [nums[nums[i]-1], nums[i]] = [nums[i], nums[nums[i]-1]];
    }
  }
  for (let i=0; i<nl; ++i) {
    if (nums[i] != i+1) {
      return i+1;
    }
  }
  return nl + 1;    
};
