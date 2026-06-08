from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        fn = head;
        en = dummy;
        for _ in range(n):
            fn = fn.next
        while fn:
            fn = fn.next
            en = en.next
        en.next = en.next.next
        return dummy.next
