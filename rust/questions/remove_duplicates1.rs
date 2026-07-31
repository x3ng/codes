impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let nl = nums.len();
        let mut vp = 0;
        let mut sp = 1;
        while sp < nl {
            let vv = nums[vp];
            vp += 1;
            nums[vp] = nums[sp];
            if nums[sp] != vv {
                sp += 1;
            } else {
                while sp < nl && nums[sp] == vv {
                    sp += 1;
                }
            }
        }
        (vp + 1) as i32
    }
}
