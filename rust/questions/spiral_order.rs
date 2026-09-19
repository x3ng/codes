const DIR: [(i32, i32); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];

impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut cs = matrix[0].len();
        let mut ns = matrix.len();
        let size = cs * ns;
        let mut ans: Vec<i32> = Vec::with_capacity(size);
        ns -= 1;
        let mut r = 0;
        let mut c = -1;
        let mut d = 0;
        while cs > 0 {
            let (dr, dc) = DIR[d];
            for _ in 0..cs {
                r += dr;
                c += dc;
                ans.push(matrix[r as usize][c as usize]);
            }
            d = (d + 1) % 4;
            (cs, ns) = (ns, cs - 1);
        }
        ans
    }
}
