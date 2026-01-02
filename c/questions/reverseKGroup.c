/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* cs = &dummy;
    struct ListNode* cur = &dummy;
    while (1) {
        for (int c=0; c<k; c++) {
            cur = cur->next;
            if (cur == NULL) {
                return dummy.next;
            }
        }
        struct ListNode* pre = cur->next;
        struct ListNode* tail = cs->next;
        struct ListNode* nxt;
        cur = tail;
        for (int c=0; c<k; c++) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        cs->next = pre;
        cs = tail;
        cur = cs;
    }
    return NULL;
}
