class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

function reverse(b: ListNode | null, e: ListNode | null): void {
    let p = null;
    while (p != e) {
        let n = b.next;
        b.next = p;
        p = b;
        b = n;
    }
}

function isPalindrome(head: ListNode | null): boolean {
    let s = head;
    let f = head.next;
    while (f && f.next) {
        s = s.next;
        f = f.next.next;
    }
    let ns = s.next;
    reverse(head, s);
    let ps = f ? s : s.next;
    while (ns && ps) {
        if (ns.val != ps.val) {
            return false;
        }
        ns = ns.next;
        ps = ps.next;
    }
    return true;
};
