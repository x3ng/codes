package main

type ListNode struct {
    Val int
    Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{}
	dummy.Next = head
	cur := head
	for i:=0; i<n; i++ {
		cur = cur.Next
	}
	nfc := dummy
	for cur != nil {
		cur = cur.Next
		nfc = nfc.Next
	}
	nfc.Next = nfc.Next.Next
	return dummy.Next
}
