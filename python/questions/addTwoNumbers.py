# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbersCarry(self, l1:Optional[ListNode], l2: Optional[ListNode], carry: int) -> Optional[ListNode]:
        if l1 is None and l2 is None:
            return carry ? ListNode(1) : None
        if l1 and l2:
            carry = carry + l1.val + l2.val
            l1.val = carry % 10
            l1.next = self.addTwoNumbersCarry(l1.next, l2.next, carry//10)
            return l1
        if l2:
            l1 = l2
        if carry:
            carry = carry + l1.val
            l1.val = carry % 10
            l1.next = self.addTwoNumbersCarry(l1.next, None, carry//10)
        return l1
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        return self.addTwoNumbersCarry(l1, l2, 0)
