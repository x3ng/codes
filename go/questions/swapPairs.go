package main

type ListNode struct {
    Val int
    Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{0, head}
	e := dummy
	for e.Next!=nil && e.Next.Next!=nil {
		p := e
		e = e.Next
		o := e.Next
		e.Next = o.Next
		o.Next = e
		p.Next = o
	}
	return dummy.Next
}
