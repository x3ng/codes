# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def symmetricLR(left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
            if left and right:
                if left.val == right.val:
                    return symmetricLR(left.left, right.right) and symmetricLR(left.right, right.left)
                return False
            if not left and not right:
                return True
            return False
        if not root:
            return True
        return symmetricLR(root.left, root.right)
