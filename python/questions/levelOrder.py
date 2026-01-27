from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        ans = []
        ln = []
        ln.append(root)
        while len(ln):
            cls = len(ln)
            clv = []
            for _ in range(cls):
                cn = ln[0]
                if cn.left:
                    ln.append(cn.left)
                if cn.right:
                    ln.append(cn.right)
                ln.pop(0)
                clv.append(cn.val)
            ans.append(clv)
        return ans
