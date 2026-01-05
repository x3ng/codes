/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    int ln = 1;
    struct ListNode* cur = head;
    while (cur->next) {
        cur = cur->next;
        ln++;
    }
    k = ln - k%ln;
    cur->next = head;
    while (k-- > 0) {
        cur = cur->next;
    }
    head = cur->next;
    cur->next = NULL;
    return head;
}
