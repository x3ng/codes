from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        def iT(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            iT(node.left)
            ans.append(node.val)
            iT(node.right)
        iT(root)
        return ans
