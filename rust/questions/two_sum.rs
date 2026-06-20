use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hm = HashMap::new();                
        for (j, &x) in nums.iter().enumerate() {
            if let Some(&i) = hm.get(&(target-x)) {
                return vec![i as i32, j as i32];
            }
            hm.insert(x, j);
        }
        unreachable!("no ans");
    }
}
