from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverse(self, s: Optional[ListNode], e: Optional[ListNode]) -> None:
        p = None
        while p != e:
            n = s.next
            s.next = p
            p = s
            s = n

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        s = head
        f = head.next
        while f and f.next:
            s = s.next
            f = f.next.next
        ns = s.next
        self.reverse(head, s)
        ps = s if f else s.next
        while ps and ns:
            if ps.val != ns.val:
                return False
            ps = ps.next
            ns = ns.next
        return True

