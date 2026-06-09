from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeList(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        cur = dummy
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 if l1 else l2
        return dummy.next

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        cl = lists
        cll = len(cl)
        while cll > 1:
            nl = []
            for i in range(0, cll-1, 2):
                nl.append(self.mergeList(cl[i], cl[i+1]))
            if cll % 2:
                nl.append(cl[-1])
            cl = nl
            cll = len(cl)
        return cl[0] if cll else None

