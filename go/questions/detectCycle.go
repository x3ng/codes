package main

type ListNode struct {
    Val int
    Next *ListNode
}

func detectCycle(head *ListNode) *ListNode {
    s := head
    f := head
    for f!=nil && f.Next!=nil {
        s = s.Next
        f = f.Next.Next
        if s == f {
            for head != f {
                head = head.Next
                f = f.Next
            }
            return head
        }
    }
    return nil
}
