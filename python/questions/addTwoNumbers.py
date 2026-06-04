from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, l1)
        cur = dummy
        carry = 0
        while l1 and l2:
            l1.val += l2.val + carry
            carry = l1.val // 10
            l1.val %= 10
            cur = l1
            l1 = l1.next
            l2 = l2.next
        cur.next = l1 if l1 else l2
        while cur.next and carry!=0:
            cur = cur.next
            cur.val += 1
            carry = cur.val // 10
            cur.val %= 10
        if carry == 1:
            cur.next = ListNode(1, None)
        return dummy.next
