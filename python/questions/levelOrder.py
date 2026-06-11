from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        ans = []
        queue = [root]        
        while len(queue):
            ql = len(queue)
            cl = []
            while ql:
                n = queue.pop(0)
                cl.append(n.val)
                if n.left:
                    queue.append(n.left)
                if n.right:
                    queue.append(n.right)
                ql -= 1
            ans.append(cl)
        return ans

            
