from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        def flate(n: Optional[TreeNode]) -> Optional[TreeNode]:
            if n is None:
                return None
            rn = n.right
            le = flate(n.left)
            if le is None:
                le = n
            n.right = n.left
            n.left = None
            re = flate(rn)
            le.right = rn
            return re if re is not None else le
        flate(root)
