function searchMatrix(matrix: number[][], target: number): boolean {
    let mr = matrix.length;
    let mc = matrix[0].length;
    let r = 0;
    let c = mc - 1;
    while (r<mr && c>=0) {
        if (matrix[r][c] == target) {
            return true;
        } else if (matrix[r][c] > target) {
            c -= 1;
        } else {
            r += 1;
        }
    }
    return false;
};
