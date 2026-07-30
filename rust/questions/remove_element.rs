impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let nl = nums.len();
        let mut r = 0;
        let mut p = 0;
        while p < nl {
            if nums[p] != val {
                nums[r] = nums[p];
                r += 1;
            }
            p += 1;
        }
        r as i32
    }
}
