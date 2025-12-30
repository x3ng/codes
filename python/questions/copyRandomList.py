"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        nmp = {}
        curr = head
        while curr:
            nmp[curr] = Node(curr.val)
            curr = curr.next
        curr = head
        while curr:
            nmp[curr].next = nmp.get(curr.next)
            nmp[curr].random = nmp.get(curr.random)
            curr = curr.next
        return nmp.get(head)
