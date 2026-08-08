impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let cl = citations.len();
        let mut rc = vec![0; cl + 1];
        for c in citations {
            if c >= cl as i32 {
                rc[cl] += 1;
            } else {
                rc[c as usize] += 1;
            }
        }
        let mut sr = 0;
        for c in (0..=cl).rev() {
            sr += rc[c];
            if sr >= c {
                return c as i32;
            }
        }
        0
    }
}
