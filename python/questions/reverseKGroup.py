# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        cs = dummy
        cur = cs
        while 1:
            for p in range(k):
                cur = cur.next
                if cur == None:
                    return dummy.next
            pre = cur.next
            cur = cs.next
            tail = cur
            for p in range(k):
                nxt = cur.next
                cur.next = pre
                pre = cur
                cur = nxt
            cs.next = pre
            cs = tail
            cur = cs
        return None
            
