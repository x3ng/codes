from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        lns = []
        ans = []
        lns.append(root)
        cls = len(lns)
        while cls:
            cs = 0
            for p in range(cls):
                cn = lns[0]
                lns.pop(0)
                if cn.left:
                    lns.append(cn.left)
                if cn.right:
                    lns.append(cn.right)
                cs += cn.val
            ans.append(cs / cls)
            cls = len(lns);
        return ans
