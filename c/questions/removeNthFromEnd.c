/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* n1b = &dummy;
    struct ListNode* cur = &dummy;
    while (n-- >= 0) {
        cur = cur->next;
    }
    while (cur) {
        cur = cur->next;
        n1b = n1b->next;
    }
    struct ListNode* ncn = n1b->next->next;
    free(n1b->next);
    n1b->next = ncn;
    return dummy.next;
}
