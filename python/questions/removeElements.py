from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        head = dummy
        while head:
            tmp = head.next
            while tmp and tmp.val==val:
                tmp = tmp.next
            head.next = tmp
            head = head.next
        return dummy.next
