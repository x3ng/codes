from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        ll = 0
        ch = head
        while ch:
            ch = ch.next
            ll += 1
        hl = ll // 2
        pl = [0] * hl
        while hl:
            hl -= 1
            pl[hl] = head.val
            head = head.next
        head = head.next if ll % 2 else head
        for i in range(len(pl)):
            if head.val != pl[i]:
                return False
            head = head.next
        return True
