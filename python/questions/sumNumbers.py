# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(pres: int, node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            pres = pres*10 + node.val
            lrs = dfs(pres, node.left) + dfs(pres, node.right)
            if lrs == 0:
                return pres
            else:
                return lrs
        return dfs(0, root)
