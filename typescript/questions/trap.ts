function trap(height: number[]): number {
  const hl = height.length;
  const st: number[] = [];
  let ans = 0;
  for (let i = 0; i < hl; ++i) {
    const h = height[i];
    while (st.length > 0 && h >= height[st[st.length - 1]]) {
      const bh = height[st.pop()!];
      if (st.length == 0) {
        break;
      }
      ans +=
        (Math.min(h, height[st[st.length - 1]]) - bh) *
        (i - st[st.length - 1] - 1);
    }
    st.push(i);
  }
  return ans;
}
