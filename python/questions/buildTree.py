from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        pp = 0
        dt = {}
        for i in range(len(inorder)):
            dt[inorder[i]] = i
        def bt(il: int, ir: int) -> Optional[TreeNode]:
            nonlocal pp, dt
            nv = preorder[pp];
            pp += 1;
            tn = TreeNode(nv)
            ip = dt[nv]
            tn.left = None if ip==il else bt(il, ip-1)
            tn.right = None if ip==ir else bt(ip+1, ir)
            return tn
        return bt(0, len(inorder)-1)
