use std::cmp::Ordering;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let mr = matrix.len();
        let mc = matrix[0].len();
        let mut r = 0;
        let mut c = mc - 1;
        while r<mr && c<mc {
            match matrix[r][c].cmp(&target) {
                Ordering::Equal => return true,
                Ordering::Less => r += 1,
                _ => c -= 1,
            }
        }
        false
    }
}
