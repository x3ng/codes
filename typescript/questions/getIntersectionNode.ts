class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

function getIntersectionNode(headA: ListNode | null, headB: ListNode | null): ListNode | null {
    let cA = headA;
    let cB = headB;
    while (cA != cB) {
        cA = cA ? cA.next : headB;
        cB = cB ? cB.next : headA;
    }
    return cA;
};
