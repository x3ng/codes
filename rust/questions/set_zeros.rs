impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let rs = matrix.len();
        let cs = matrix[0].len();
        let r0 = matrix[0].contains(&0);
        for r in 1..rs {
            let mut c0 = false;
            for c in 0..cs {
                if matrix[r][c] == 0 {
                    matrix[0][c] = 0;
                    c0 = true;
                }
            }
            if c0 {
                matrix[r].fill(0);
            }
        }
        for c in 0..cs {
            if matrix[0][c] == 0 {
                for r in 0..rs {
                    matrix[r][c] = 0;
                }
            }
        }
        if r0 {
            matrix[0].fill(0);
        }
    }
}
