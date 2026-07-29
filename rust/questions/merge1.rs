impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let m = m as usize;
        let n = n as usize;
        let mut p1 = m - 1;
        let mut p2 = n - 1;
        let mut p = m + n - 1;
        while p2 < n {
            if p1<m && nums1[p1]>nums2[p2] {
                nums1[p] = nums1[p1];
                p1 -= 1;
            } else {
                nums1[p] = nums2[p2];
                p2 -= 1;
            }
            p -= 1;
        }
    }
}
