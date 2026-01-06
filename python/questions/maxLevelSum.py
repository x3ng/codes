# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        mas = -inf
        tnl = [root]
        level = 1
        while len(tnl):
            tmp = tnl
            tnl = []
            ts = 0
            for n in tmp:
                ts += n.val
                if n.left:
                    tnl.append(n.left)
                if n.right:
                    tnl.append(n.right)
            if ts > mas:
                mas = ts
                ans = level
            level += 1
        return ans
