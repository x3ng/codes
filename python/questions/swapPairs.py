from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head);
        cur = dummy
        while cur.next and cur.next.next:
            cn = cur.next
            cnn = cn.next
            cn.next = cnn.next
            cnn.next = cn
            cur.next = cnn
            cur = cn
        return dummy.next
