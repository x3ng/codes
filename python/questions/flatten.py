# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def pft(node: Optional[TreeNode]) -> Optional[TreeNode]:
            rn = node.right
            tail = node
            if node.left:
                node.right = node.left
                tail = pft(node.left)
                node.left = None
            if rn:
                tail.right = rn
                tail = pft(node.right)
            return tail
        if root:
            pft(root)
        else:
            return
