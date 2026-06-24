impl Solution {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let n_usize = n as usize;
        let mut res = Vec::new();
        let mut col = vec![false; n_usize];
        let mut md = vec![false; 2 * n_usize - 1];
        let mut pd = vec![false; 2 * n_usize - 1];
        let mut path = vec![vec!['.'; n_usize]; n_usize];

        fn bt(
            r: usize,
            n: usize,
            path: &mut Vec<Vec<char>>,
            col: &mut Vec<bool>,
            md: &mut Vec<bool>,
            pd: &mut Vec<bool>,
            res: &mut Vec<Vec<String>>,
        ) {
            if r == n {
                let bd: Vec<String> = path.iter().map(|line| line.iter().collect()).collect();
                res.push(bd);
                return;
            }
            for c in 0..n {
                let mp = r as isize - c as isize + (n - 1) as isize;
                let mp = mp as usize;
                let pp = r + c;
                if !col[c] && !md[mp] && !pd[pp] {
                    col[c] = true;
                    md[mp] = true;
                    pd[pp] = true;
                    path[r][c] = 'Q';
                    bt(r+1, n, path, col, md, pd, res);
                    path[r][c] = '.';
                    col[c] = false;
                    md[mp] = false;
                    pd[pp] = false;
                }
            }
        }

        bt(0, n_usize, &mut path, &mut col, &mut md, &mut pd, &mut res);
        res
    }
}
