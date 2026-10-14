class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}


function reverseList(head: ListNode | null): ListNode | null {
    let pn = null;
    while (head != null) {
        let nh = head.next;
        head.next = pn;
        pn = head;
        head = nh
    }
    return pn;
};
