const DIR = [[0, 1], [1, 0], [0, -1], [-1, 0]];

function spiralOrder(matrix: number[][]): number[] {
    let cs= matrix[0].length;
    let ns = matrix.length - 1;
    let ans = new Array<number>();
    let r = 0;
    let c = -1;
    let d = 0;
    while (cs) {
      for (let i=0; i<cs; ++i) {
        r += DIR[d][0];
        c += DIR[d][1];
        ans.push(matrix[r][c]);
      }
      --cs;
      [cs, ns] = [ns, cs];
      d = (d + 1) % 4;
    }
    return ans;
};
