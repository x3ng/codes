from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        ans = 0
        ps = [0]
        def pS(n: Optional[TreeNode]) -> None:
            nonlocal ans, ps
            if n is None:
                return
            sps = ps[-1] + n.val
            for p in ps:
                if sps-p == targetSum:
                    ans += 1
            ps.append(sps)
            pS(n.left)
            pS(n.right)
            ps.pop(-1)
        pS(root)
        return ans
