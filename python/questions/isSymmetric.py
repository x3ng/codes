from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def cLR(l: Optional[TreeNode], r: Optional[TreeNode]) -> bool:
            if l and r:
                return cLR(l.left, r.right) and cLR(l.right, r.left) if l.val==r.val else False
            if l is None and r is None:
                return True
            return False
        return cLR(root.left, root.right) if root else True
