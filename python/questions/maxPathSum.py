# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum = -inf
        def dfs(node: Optional[TreeNode]) -> int:
            nonlocal maxSum
            if node is None:
                return 0
            l = max(dfs(node.left), 0)
            r = max(dfs(node.right), 0)
            maxSum = max(maxSum, node.val+l+r)
            return max(l, r)+node.val
        dfs(root)
        return maxSum
