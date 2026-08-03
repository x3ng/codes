impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut mv = prices[0];
        let mut mp = 0;
        for p in prices {
            mv = mv.min(p);
            mp = mp.max(p - mv);
        }
        return mp;
    }
}
