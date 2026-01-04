/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* pre = &dummy;
    struct ListNode* cur = head;
    struct ListNode* dns;
    while (cur) {
        if (cur->next && cur->val==cur->next->val) {
            dns = pre;
            while (cur->next && cur->val==cur->next->val) {
                pre = cur;
                cur = cur->next;
                free(pre);
            }
            pre = cur;
            cur = cur->next;
            free(pre);
            dns->next = cur;
            pre = dns;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }
    return dummy.next;
}
