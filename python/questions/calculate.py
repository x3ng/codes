class Solution:
    def calculate(self, s: str) -> int:
        ops = [1]
        ans = 0
        sign = 1
        n = len(s)
        for i in range(n):
            if s[i] == ' ':
                i = i + 1
            elif s[i] == '+':
                sign = ops[-1]
                i = i + 1
            elif s[i] == '-':
                sign = -ops[-1]
                i = i + 1
            elif s[i] == '(':
                ops.append(sign)
                i = i + 1
            elif s[i] == ')':
                ops.pop()
                i = i + 1
            else:
                nums = 0
                while i<n and '0'<=s[i] and s[i]<='9':
                    nums = nums*10 + int(s[i])
                    i = i + 1
                ans += sign * nums
        return ans
