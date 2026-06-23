impl Solution {
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let chars: Vec<char> = s.chars().collect();
        let n = chars.len();
        let mut res = Vec::new();
        let mut path = Vec::new();
        let mut ip = vec![vec![false; n]; n];

        for i in 0..n {
            ip[i][i] = true;
        }

        for i in 0..n-1 {
            if chars[i] == chars[i+1] {
                ip[i][i+1] = true;
            }
        }
        
        for len in 3..=n {
            for i in 0..=n-len {
                let j = i + len - 1;
                if chars[i] == chars[j] && ip[i+1][j-1] {
                    ip[i][j] = true;
                }
            }
        }

        fn backtrack (
            start: usize,
            chars: &[char],
            ip: &Vec<Vec<bool>>,
            path: &mut Vec<String>,
            res: &mut Vec<Vec<String>>,
        ) {
            if start == chars.len() {
                res.push(path.clone());
                return;
            }

            for end in start..chars.len() {
                if ip[start][end] {
                    let sub: String = chars[start..=end].iter().collect();
                    path.push(sub);
                    backtrack(end+1, chars, ip, path, res);
                    path.pop();
                }
            }
        }

        backtrack(0, &chars, &ip, &mut path, &mut res);
        res
    }
}
