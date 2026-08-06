impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let nl = nums.len();
        let mut mp: usize = 0;
        let mut p: usize = 0;
        while p <= mp {
            mp = mp.max(p + nums[p] as usize);
            if mp >= nl - 1 {
                return true;
            }
            p += 1;
        }
        return false;
    }
}
