from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        cA = headA
        cB = headB
        while cA != cB:
            cA = cA.next if cA else headB
            cB = cB.next if cB else headA
        return cA
