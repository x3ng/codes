impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let ml = matrix.len();        
        for r in 0..ml/2 {
            for c in r..ml-1-r {
                let pos = [(r, c), (ml-1-c, r), (ml-1-r, ml-1-c), (c, ml-1-r)];
                let tv = matrix[r][c];
                for i in 0..3 {
                    matrix[pos[i].0][pos[i].1] = matrix[pos[i+1].0][pos[i+1].1];
                }
                matrix[pos[3].0][pos[3].1] = tv;
            }
        }
    }
}
