function setZeroes(matrix: number[][]): void {
  const rl = matrix.length;
  const cl = matrix[0].length;
  const r0 = matrix[0].includes(0);
  for (let r=1; r<rl; ++r) {
    let c0 = false;
    for (let c=0 ; c<cl; ++c) {
      if (matrix[r][c] == 0) {
        matrix[0][c] = 0;
        c0 = true;
      }
    }
    if (c0) {
      matrix[r].fill(0);
    }
  }
  for (let c=0; c<cl; ++c) {
    if (matrix[0][c] == 0) {
      for (let r=1; r<rl; ++r) {
        matrix[r][c] = 0;
      }
    }
  }
  if (r0) {
    matrix[0].fill(0);
  }
};
