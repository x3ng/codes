# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        ts = []
        def dfs(root: Optioal[TreeNode]) -> int:
            if root == None:
                return 0
            sum = root.val + dfs(root.left) + dfs(root.right)
            ts.append(sum)
            return sum
        total = dfs(root)
        ans = 0
        for ns in ts:
            ans = max(ans, ns*(total-ns))
        return ans % 1_000_000_007
