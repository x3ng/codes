# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head == None:
            return None
        ln = 1
        cur = head
        while cur.next:
            cur = cur.next
            ln += 1
        k = ln - k % ln
        cur.next = head
        while k > 0:
            k -= 1
            cur = cur.next
        head = cur.next
        cur.next = None
        return head
