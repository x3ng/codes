impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = height.len() - 1;
        let mut a = 0;
        while l < r {
            let hl = height[l];
            let hr = height[r];
            let w = (r - l) as i32;
            if hl > hr {
                a = a.max(hr * w);
                r -= 1;
            } else {
                a = a.max(hl * w);
                l += 1;
            }
        }
        a
    }
}
