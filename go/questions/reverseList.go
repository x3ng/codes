package main

type ListNode struct {
    Val int
    Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
    var pn *ListNode
    pn = nil
    for head != nil {
        nh := head.Next
        head.Next = pn
        pn = head
        head = nh
    }
    return pn
}
