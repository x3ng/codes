# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        inm = {}
        for p in range(len(inorder)):
            inm[inorder[p]] = p
        def build(ine: int, poste: int, len: int) -> Optional[TreeNode]:
            if len == 0:
                return None
            ip = inm[postorder[poste]]
            rl = ine - ip
            return TreeNode(postorder[poste], build(ip-1, poste-rl-1, len-rl-1), build(ine, poste-1, rl))
        return build(len(inorder)-1, len(postorder)-1, len(inorder))
            
