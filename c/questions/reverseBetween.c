/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->next = head;
    head = dummy;
    for (int p=0; p<left-1; p++) {
        head = head->next;
    }
    struct ListNode* rs = head;
    struct ListNode* re = head->next;
    struct ListNode* pre;
    struct ListNode* nex = head->next;
    for (int p=0; p<right-left+1; p++) {
        pre = head;
        head = nex;
        nex = head->next;
        head->next = pre;
    }
    rs->next = head;
    re->next = nex;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}
