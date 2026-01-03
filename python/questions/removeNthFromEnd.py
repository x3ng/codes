# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        n1b = dummy
        cur = dummy
        for _ in range(n+1):
            cur = cur.next
        while cur:
            cur = cur.next
            n1b = n1b.next
        ncn = n1b.next.next
        n1b.next = ncn
        return dummy.next
        
