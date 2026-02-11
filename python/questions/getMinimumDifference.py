# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        ans = float('inf')
        pre = None
        def dfs(node: Optional[TreeNode]) -> void:
            nonlocal pre, ans
            if node is None:
                return
            if node.left:
                dfs(node.left)
            ans = min(ans, node.val-pre.val) if pre else ans
            pre = node
            if node.right:
                dfs(node.right)
        dfs(root)
        return ans
