use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }
        let st: HashSet<i32> = nums.iter().cloned().collect();
        let mut ans = 1;
        for &n in &st {
            if !st.contains(&(n - 1)) {
                let mut cn = n;
                let mut cl = 1;
                while st.contains(&(cn + 1)) {
                    cn += 1;
                    cl += 1;
                }
                ans = ans.max(cl);
            }
        }
        ans
    }
}
