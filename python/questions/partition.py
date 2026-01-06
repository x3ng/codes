# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        sln = ListNode(0, None)
        bln = ListNode(0, None)
        scn = sln
        bcn = bln
        while head:
            if head.val < x:
                scn.next = head
                scn = scn.next
            else:
                bcn.next = head
                bcn = bcn.next
            head = head.next
        bcn.next = None
        scn.next = bln.next
        return sln.next
        
