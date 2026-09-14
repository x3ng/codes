impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let nl = nums.len();
        let mut ans = vec![1; nl];
        for p in (0..nl - 1).rev() {
            ans[p] = nums[p + 1] * ans[p + 1];
        }
        let mut pre = nums[0];
        for p in (1..nl) {
            ans[p] *= pre;
            pre *= nums[p];
        }
        ans
    }
}
