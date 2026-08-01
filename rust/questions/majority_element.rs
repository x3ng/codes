impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut v = 0;
        let mut p = 0;
        for n in nums {
            match v {
                0 => {
                    p = n;
                    v = 1;
                }
                _ if n == p => v += 1,
                _ => v -= 1,
            }
        }
        p
    }
}
