package main

type ListNode struct {
    Val int
    Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	cA, cB := headA, headB
	for cA != cB {
		if cA == nil {
			cA = headB
		} else {
			cA = cA.Next
		}
		if cB == nil {
			cB = headA
		} else {
			cB = cB.Next
		}
	}
	return cA
}
