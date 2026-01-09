# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def build(pres: int, ins: int, tlen: int) -> Optional[TreeNode]:
            if tlen == 0:
                return None
            ip = 0
            for ip in range(ins, ins+tlen):
                if inorder[ip] == preorder[pres]:
                    break
            ll = ip - ins
            return TreeNode(inorder[ip], build(pres+1, ins, ip-ins), build(pres+ll+1, ip+1, ins+tlen-ip-1))
        return build(0, 0, len(inorder))
