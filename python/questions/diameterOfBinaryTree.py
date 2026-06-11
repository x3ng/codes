from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(n: Optional[TreeNode]) -> int:
            nonlocal ans
            if n is None:
                return 0
            ld = dfs(n.left)
            rd = dfs(n.right)
            ans = max(ans, ld+rd)
            return max(ld, rd)+1
        dfs(root)
        return ans
