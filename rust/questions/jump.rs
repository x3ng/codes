impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let nl = nums.len();
        let mut r: usize = 0;
        let mut l: usize = 0;
        let mut s = 0;
        while l <= r {
            if r >= nl - 1 {
                return s;
            }
            let cr = r;
            while l <= cr {
                r = r.max(nums[l] as usize + l);
                l += 1;
            }
            s += 1;
        }
        return -1;
    }
}
