function hIndex(citations: number[]): number {
  const cl = citations.length;
  const rc: number[] = Array(cl + 1).fill(0);
  for (const c of citations) {
    if (c >= cl) {
      rc[cl] += 1;
    } else {
      rc[c] += 1;
    }
  }
  let sr = 0;
  for (let p = cl; p >= 0; --p) {
    sr += rc[p];
    if (sr >= p) {
      return p;
    }
  }
  return 0;
}
