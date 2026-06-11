from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        ans = 0
        def io(n: Optional[TreeNode]) -> None:        
            nonlocal k, ans
            if n is None:
                return
            io(n.left)
            k -= 1
            if k == 0:
                ans = n.val
                return
            io(n.right)
        io(root)
        return ans
