impl Solution {

    const DIRS: [(isize, isize); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        let rs = board.len();
        let cs = board[0].len();
        let wd: Vec<char> = word.chars().collect();
        let ws = wd.len();
        let mut fg = vec![vec![false; cs]; rs];
        fn fw(r: usize, c: usize, p: usize, rs: usize, cs: usize, ws: usize, bd: &Vec<Vec<char>>, wd: &[char], fg: &mut Vec<Vec<bool>>) -> bool {
            if bd[r][c] != wd[p] || fg[r][c] {
                return false;
            }
            if p == ws-1 {
                return true;
            }
            fg[r][c] = true;
            for (dr, dc) in Solution::DIRS {
                let nr = r as isize + dr;
                let nc = c as isize + dc;
                if nr>=0 && nc>=0 {
                    let vnr = nr as usize;
                    let vnc = nc as usize;
                    if vnr < rs && vnc < cs {
                        if fw(vnr, vnc, p+1, rs, cs, ws, bd, wd, fg) {
                            return true;
                        }
                    }
                }
            }
            fg[r][c] = false;
            return false;
        }
        for r in 0..rs {
            for c in 0..cs {
                if fw(r, c, 0, rs, cs, ws, &board, &wd, &mut fg) {
                    return true;
                }
            }
        }
        false
    }
}
