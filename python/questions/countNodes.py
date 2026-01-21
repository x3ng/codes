# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        def nodeExist(root: Optional[TreeNode], level: int, nid: int) -> int:
            bs = 1 << (level - 1)
            node = root
            while bs:
                if bs & nid:
                    node = node.right
                else:
                    node = node.left
                bs >>= 1
            return node is not None
        
        node = root
        level = 0
        while node.left:
            node = node.left
            level += 1
        minn = 1 << level
        maxn = (1 << (level + 1)) - 1
        while minn < maxn:
            midn = (minn + maxn + 1) // 2
            if nodeExist(root, level, midn):
                minn = midn
            else:
                maxn = midn - 1
        return minn
