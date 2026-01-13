class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        ta = 0
        ew = defaultdict(int)
        for _, y, l in squares:
            ta += l ** 2
            ew[y] += l
            ew[y+l] -= l
        ca = 0
        csw = 0
        for cy, ny in pairwise(sorted(ew)):
            csw += ew[cy]
            ca += (ny-cy) * csw
            if ca*2 >= ta:
                return ny-(ca-ta/2)/csw
            
