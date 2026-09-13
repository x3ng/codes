impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let nl = nums.len();
        let k = k as usize % nl;
        nums.reverse();
        nums[..k].reverse();
        nums[k..].reverse();
    }
}
