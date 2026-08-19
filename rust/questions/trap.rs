impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let hl = height.len();
        let mut st = Vec::new();
        let mut ans = 0;
        for (i, &h) in height.iter().enumerate() {
            while st.len() > 0 && h >= height[*st.last().unwrap()] {
                let bh = height[st.pop().unwrap()];
                if st.len() == 0 {
                    break;
                }
                ans += (h.min(height[st[st.len() - 1]]) - bh) * ((i - st[st.len() - 1]) as i32 - 1);
            }
            st.push(i);
        }
        ans
    }
}
