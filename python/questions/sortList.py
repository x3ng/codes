from typing import Optional, Tuple

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeList(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Tuple[Optional[ListNode], Optional[ListNode]]:
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
        while cur.next:
            cur = cur.next
        return dummy.next, cur

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head) 
        rg = 1
        ll = 0
        cur = head
        while cur:
            ll += 1
            cur = cur.next
        while rg < ll:
            pre = dummy
            gs = 1
            while 1:
                l1 = pre.next
                if l1 is None or gs+rg>ll:
                    break
                cur = l1
                step = 1
                while step < rg:
                    step += 1
                    cur = cur.next
                gs += rg
                l2 = cur.next
                if l2 is None:
                    break
                elif gs+rg>ll:
                    cur.next = None
                    pre.next, mt = self.mergeList(l1, l2)
                    break
                cur.next = None
                step = 1
                cur = l2
                while step < rg:
                    cur = cur.next
                    step += 1
                nxt = cur.next
                cur.next = None
                mh, mt = self.mergeList(l1, l2)
                pre.next = mh
                mt.next = nxt
                pre = mt
                gs += rg
            rg *= 2
        return dummy.next
