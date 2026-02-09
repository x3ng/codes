# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        nodes = []
        def getnodes(node: Optional[TreeNode]) -> void:
            if node.left:
                getnodes(node.left)
            nodes.append(node)
            if node.right:
                getnodes(node.right)
        getnodes(root)
        def gentree(s: int, e: int) -> Optional[TreeNode]:
            if s > e:
                return None
            elif s == e:
                cn = nodes[s]
                cn.left = None
                cn.right = None
                return cn
            m = (s + e) // 2
            cn = nodes[m]
            cn.left = gentree(s, m-1)
            cn.right = gentree(m+1, e)
            return cn
        return gentree(0, len(nodes)-1)
