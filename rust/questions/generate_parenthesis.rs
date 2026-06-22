impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut ans = Vec::new();
        let len = (n * 2) as usize;
        let mut tmp = vec![' '; len];
        fn bs(p: usize, l: i32, tmp: &mut Vec<char>, ans: &mut Vec<String>, n: i32) -> () {
            if l == n {
                for i in p..tmp.len() {
                    tmp[i] = ')';
                }
                ans.push(tmp.iter().collect());
                return;
            }
            if (p as i32) < l*2 {
                tmp[p] = ')';
                bs(p+1, l, tmp, ans, n);
            }
            tmp[p] = '(';
            bs(p+1, l+1, tmp, ans, n);
        }
        bs(0, 0, &mut tmp, &mut ans, n);
        ans
    }
}
