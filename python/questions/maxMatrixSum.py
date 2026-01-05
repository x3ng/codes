class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        ans = 0
        neg_cnt = 0
        mn = inf
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if matrix[r][c] < 0:
                    neg_cnt += 1
                    ans += -matrix[r][c]
                    mn = min(mn, -matrix[r][c])
                else:
                    ans += matrix[r][c]
                    mn = min(mn, matrix[r][c])
        if neg_cnt%2 == 0:
            return ans
        return ans-mn*2
