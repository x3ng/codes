function longestConsecutive(nums: number[]): number {
  if (nums.length <= 0) {
    return 0;
  }
  const st: Set<number> = new Set(nums);
  let ans = 1;
  for (const n of st) {
    if (!st.has(n - 1)) {
      let cn = n;
      let cl = 1;
      while (st.has(cn + 1)) {
        cn += 1;
        cl += 1;
      }
      ans = Math.max(ans, cl);
    }
  }
  return ans;
}
