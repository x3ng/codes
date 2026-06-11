from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        pre = -float('inf')
        def io(n: Optional[TreeNode]) -> bool:
            nonlocal pre
            if n is None:
                return True
            if not io(n.left):
                return False
            if n.val <= pre:
                return False
            pre = n.val
            return io(n.right)
        return io(root)
