function maxArea(height: number[]): number {
  let l = 0;
  let r = height.length - 1;
  let a = 0;
  while (l < r) {
    const hl = height[l];
    const hr = height[r];
    const w = r - l;
    if (hl > hr) {
      a = Math.max(a, hr * w);
      --r;
    } else {
      a = Math.max(a, hl * w);
      ++l;
    }
  }
  return a;
}
