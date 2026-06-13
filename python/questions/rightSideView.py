from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        def io(n: Optional[TreeNode], d: int) -> None:
            if n is None:
                return
            if d > len(ans):
                ans.append(n.val)
            io(n.right, d+1)
            io(n.left, d+1)
        io(root, 1)
        return ans
