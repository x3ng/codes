package main

type ListNode struct {
    Val int
    Next *ListNode
}

func reverse(b, e *ListNode) {
	var p *ListNode
	p = nil
	for p != e {
		n := b.Next
		b.Next = p
		p = b
		b = n
	}
}

func isPalindrome(head *ListNode) bool {
	s := head
	f := head.Next
	for f!=nil && f.Next!=nil {
		s = s.Next
		f = f.Next.Next
	}
	ns := s.Next;
	reverse(head, s);
	var ps *ListNode
	if f != nil {
		ps = s
	} else {
		ps = s.Next
	}
	for ns!=nil && ps!=nil {
		if ns.Val != ps.Val {
			return false
		}
		ns = ns.Next
		ps = ps.Next
	}
	return true
}
