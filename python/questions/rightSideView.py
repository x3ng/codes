from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        tmp = []
        if root is not None:
            tmp.append(root)
        else:
            return [];
        ans = []
        while len(tmp):
            ans.append(tmp[-1].val)
            n = len(tmp)
            for p in range(n):
                cn = tmp[0]
                tmp.pop(0)
                if cn.left:
                    tmp.append(cn.left)
                if cn.right:
                    tmp.append(cn.right)
        return ans;
