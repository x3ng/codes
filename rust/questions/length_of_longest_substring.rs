use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let s = s.as_bytes();
        let mut mp = HashMap::new();
        let mut l = 0;
        let mut r = 0;
        let mut ans = 0;
        while r < s.len() {
            let rc = s[r];
            if let Some(&pp) = mp.get(&rc) {
                ans = ans.max((r - l) as i32);
                l = l.max(pp + 1);
            }
            mp.insert(rc, r);
            r += 1;
        }
        ans = ans.max((r - l) as i32);
        ans
    }
}
