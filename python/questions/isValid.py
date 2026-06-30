class Solution:
    def isValid(self, s: str) -> bool:
        dic = {')': '(', ']': '[', '}': '{'}
        stack = ['0']
        for c in s:
            if c in ['(', '[', '{']:
                stack.append(c)
            else:
                if dic[c] != stack.pop():
                    return False
        return len(stack) == 1
