import typing
from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        nst = []
        p = 1
        while p < left:
            p += 1
            head = head.next
        rs = head
        head = head.next
        while p < right:
            nst.append(head)
            head = head.next
            p += 1
        rs.next = head
        rs = rs.next
        head = head.next if head.next else None
        while len(nst):
            rs.next = nst[-1]
            rs = rs.next
            nst.pop()
        rs.next = head
        return dummy.next
