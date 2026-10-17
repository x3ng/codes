package main

type ListNode struct {
    Val int
    Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{}
	cur := dummy
	carry := 0
	for l1!=nil || l2!=nil {
		v1 := 0
		v2 := 0
		if l1 != nil {
			v1 = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			v2 = l2.Val
			l2 = l2.Next
		}
		s := v1 + v2 + carry
		cur.Next = &ListNode{s%10, nil}
		carry = s / 10
		cur = cur.Next
	}
	if carry > 0 {
		cur.Next = &ListNode{1, nil}
	}
	return dummy.Next
}
