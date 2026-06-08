from typing import Optional

class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        dt = {}
        dt[None] = None
        cur = head
        while cur is not None:
            dt[cur] = Node(cur.val)
            cur = cur.next
        cur = head
        while cur is not None:
            dt[cur].next = dt[cur.next]
            dt[cur].random = dt[cur.random]
            cur = cur.next
        return dt[head]
