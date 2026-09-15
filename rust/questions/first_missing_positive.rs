impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
        let nl = nums.len();
        for p in 0..nl {
            while nums[p] > 0 && nums[p] <= nl as i32 {
                let np = nums[p] as usize;
                if nums[np - 1] == nums[p] {
                    break;
                }
                nums.swap(p, np - 1);
            }
        }
        for p in 0..nl {
            if nums[p] != p as i32 + 1 {
                return p as i32 + 1;
            }
        }
        nl as i32 + 1
    }
}
