# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def deepestSubTree(root: Optional[TreeNode]) -> tuple[Optional[TreeNode], int]:
            if root is None:
                return None, 0
            ln, lh = deepestSubTree(root.left)
            rn, rh = deepestSubTree(root.right)
            if lh > rh:
                return ln, lh+1
            if rh > lh:
                return rn, rh+1
            return root, lh+1
        return deepestSubTree(root)[0]
            
