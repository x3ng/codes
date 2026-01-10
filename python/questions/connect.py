"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        q = deque()
        q.append(root)
        while len(q):
            nll = len(q)
            for np in range(nll):
                nn = q.popleft()
                if np == nll-1:
                    nn.next = None
                else:
                    nn.next = q[0]
                if nn.left:
                    q.append(nn.left)
                if nn.right:
                    q.append(nn.right)
        return root
