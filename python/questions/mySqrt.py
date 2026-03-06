class Solution:
    def mySqrt(self, x: int) -> int:
        nx = x
        while nx*nx > x:
            nx = (nx + x//nx) // 2
        return nx
