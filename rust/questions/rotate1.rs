impl Solution {
    pub fn rt(nums: &mut Vec<i32>, mut l: usize, mut r: usize) {
        while l < r {
            nums.swap(l, r);
            l += 1;
            r -= 1;
        }
    }

    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let nl = nums.len();
        let mut k = k % nl as i32;
        if k > 0 {
            Self::rt(nums, 0, (nl - 1) as usize);
            Self::rt(nums, 0, (k - 1) as usize);
            Self::rt(nums, k as usize, (nl - 1) as usize);
        }
    }
}
