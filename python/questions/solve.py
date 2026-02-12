class Solution:
    def solve(self, board: List[List[str]]) -> None:
        cl = len(board)
        rl = len(board[0])
        def markarea(c: int, r: int) -> None:
            nonlocal board, cl, rl
            board[c][r] = 'M'
            if c > 0 and board[c-1][r] == 'O':
                markarea(c-1, r)
            if c < cl-1 and board[c+1][r] == 'O':
                markarea(c+1, r)
            if r > 0 and board[c][r-1] == 'O':
                markarea(c, r-1)
            if r < rl-1 and board[c][r+1] == 'O':
                markarea(c, r+1)
        for p in range(rl):
            if board[0][p] == 'O':
                markarea(0, p)
            if board[cl-1][p] == 'O':
                markarea(cl-1, p)
        for p in range(1, cl):
            if board[p][0] == 'O':
                markarea(p, 0)
            if board[p][rl-1] == 'O':
                markarea(p, rl-1)
        for cp in range(cl):
            for rp in range(rl):
                board[cp][rp] = 'O' if board[cp][rp] == 'M' else 'X'
