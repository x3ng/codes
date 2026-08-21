function lengthOfLongestSubstring(s: string): number {
  let mp: Map<string, number> = new Map<string, number>();
  let l = 0;
  let r = 0;
  let ans = 0;
  for (; r < s.length; ++r) {
    const cc = s[r];
    if (mp.has(cc)) {
      ans = Math.max(ans, r - l);
      l = Math.max(l, mp.get(cc) + 1);
    }
    mp.set(cc, r);
  }
  ans = Math.max(ans, r - l);
  return ans;
}
