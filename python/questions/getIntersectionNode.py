from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        cA = headA
        cB = headB
        while cA and cB:
            cA = cA.next
            cB = cB.next
        if cB == None:
            headA, headB = headB, headA
            cA, cB = cB, cA
        while cB:
            cB = cB.next
            headB = headB.next
        while headA != headB:
            headA = headA.next
            headB = headB.next
        return headA
