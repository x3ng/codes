from typing import List

class Solution:
    DIRS = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    def exist(self, board: List[List[str]], word: str) -> bool:
        rs = len(board)
        cs = len(board[0])
        ws = len(word)
        fg = [[False] * cs for _ in range(rs)]
        def fw(r: int, c: int, p: int) -> bool:
            if r<0 or r>=rs or c<0 or c>=cs or fg[r][c] or board[r][c]!=word[p]:
                return False
            if p == ws-1:
                return True
            fg[r][c] = True
            for dr, dc in self.DIRS:
                if fw(r+dr, c+dc, p+1):
                    return True
            fg[r][c] = False
            return False
        for i in range(rs):
            for j in range(cs):
                if fw(i, j, 0):
                    return True
        return False
