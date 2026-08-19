impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let nl = nums.len();
        let mut sn = nums.clone();
        sn.sort();
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let e2 = sn[nl - 2] + sn[nl - 1];
        for i in 0..nl - 2 {
            if sn[i] + sn[i + 1] + sn[i + 2] > 0 {
                break;
            }
            if (i > 0 && sn[i] == sn[i - 1]) || (sn[i] + e2 < 0) {
                continue;
            }
            let mut l = i + 1;
            let mut r = nl - 1;
            while l < r {
                let s = sn[i] + sn[l] + sn[r];
                if s > 0 {
                    r -= 1;
                } else if s < 0 {
                    l += 1;
                } else {
                    ans.push(vec![sn[i], sn[l], sn[r]]);
                    l += 1;
                    while l < r && sn[l] == sn[l - 1] {
                        l += 1;
                    }
                    r -= 1;
                    while l < r && sn[r] == sn[r + 1] {
                        r -= 1;
                    }
                }
            }
        }
        ans
    }
}
