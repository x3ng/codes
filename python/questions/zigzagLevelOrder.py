# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        d = 1
        ans = []
        nq = [root]
        while len(nq):
            cl = len(nq);
            cln = [0 for _ in range(cl)]
            p = 0 if d == 1 else cl-1
            while cl:
                cl -= 1
                cn = nq[0]
                nq.pop(0)
                if cn.left:
                    nq.append(cn.left)
                if cn.right:
                    nq.append(cn.right)
                cln[p] = cn.val
                p += d
            ans.append(cln)
            d *= -1
        return ans
