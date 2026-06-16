from typing import List
from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rl = len(grid)
        cl = len(grid[0])
        dq = deque()
        fresh = 0
        for i in range(rl):
            for j in range(cl):
                if grid[i][j] == 2:
                    dq.append([i, j])
                if grid[i][j] == 1:
                    fresh += 1
        if fresh == 0:
            return 0
        ans = 0
        def rot(i: int, j: int) -> None:
            if i<0 or i>=rl or j<0 or j>=cl or grid[i][j]!=1:
                return
            grid[i][j] = 2
            dq.append([i, j])
        while dq:
            cs = len(dq)
            for _ in range(cs):
                i, j = dq.popleft()
                rot(i-1, j)
                rot(i+1, j)
                rot(i, j-1)
                rot(i, j+1)
                cs -= 1
            ans += 1 if len(dq) else 0
            fresh -= len(dq)
        return ans if fresh==0 else -1
