from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = -float('inf')
        def mp(n: Optional[TreeNode]) -> int:
            nonlocal ans
            if n is None:
                return 0
            l = max(mp(n.left), 0)
            r = max(mp(n.right), 0)
            ans = max(ans, n.val+l+r)
            return n.val + max(l, r)
        mp(root)
        return int(ans)
