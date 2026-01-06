/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode sln;
    struct ListNode bln;
    struct ListNode* scn = &sln;
    struct ListNode* bcn = &bln;
    while (head) {
        if (head->val < x) {
            scn->next = head;
            scn = scn->next;
        } else {
            bcn->next = head;
            bcn = bcn->next;
        }
        head = head->next;
    }
    bcn->next = NULL;
    scn->next = bln.next;
    return sln.next;
}
