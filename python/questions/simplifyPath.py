class Solution:
    def simplifyPath(self, path: str) -> str:
        stk = []
        for s in path.split('/'):
            if s == "" or s == ".":
                continue
            elif s != "..":
                stk.append(s)
            elif stk:
                stk.pop()
        return '/' + '/'.join(stk)
    
