class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}


function hasCycle(head: ListNode | null): boolean {
    let s = head;
    let f = head;
    while (f && f.next) {
        s = s.next;
        f = f.next.next;
        if (s == f) {
            return true;
        }
    }
    return false;
};
