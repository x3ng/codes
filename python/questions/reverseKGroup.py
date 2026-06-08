from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)        
        fn = dummy
        en = dummy
        for _ in range(k):
            fn = fn.next
        nr = True if fn else False
        while nr:
            nf = fn.next
            ne = en.next
            cur = None
            nxt = en.next
            en.next = fn
            for _ in range(k):
                nxtn = nxt.next
                nxt.next = cur
                fn = fn.next if fn else None
                cur = nxt
                nxt = nxtn
            nr = True if fn else False
            en = ne
            ne.next = nf
        return dummy.next
