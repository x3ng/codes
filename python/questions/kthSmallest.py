# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def inorder(node: Optional[TreeNode]) -> Generator[int, None, None]:
            if node is None:
                return
            yield from inorder(node.left)
            yield node.val
            yield from inorder(node.right)

        gen = inorder(root)
        for _ in range(k):
            ans = next(gen)
        return ans
