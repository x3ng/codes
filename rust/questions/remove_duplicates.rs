impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let nl = nums.len();
        let mut vp = 0;
        let mut sp = 0;
        while sp < nl {
            if nums[sp] != nums[vp] {
                vp += 1;
                nums[vp] = nums[sp];
            }
            sp += 1;
        }
        (vp + 1) as i32
    }
}
