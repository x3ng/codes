function rotate(matrix: number[][]): void {
    let ml = matrix.length;
    for (let r=0; r<ml/2; ++r) {
        for (let c=r; c<ml-1-r; ++c) {
            [matrix[r][c], matrix[ml-1-c][r], matrix[ml-1-r][ml-1-c], matrix[c][ml-1-r]] = [matrix[ml-1-c][r], matrix[ml-1-r][ml-1-c], matrix[c][ml-1-r], matrix[r][c]];
        }
    }
};
