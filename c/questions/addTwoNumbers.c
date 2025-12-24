/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbersCarry(struct ListNode* l1, struct ListNode* l2, int carry) {
    if (!l1 && !l2) {
        if (carry) {
            struct ListNode* e = malloc(sizeof(struct ListNode));
            e->val = 1;
            e->next = NULL;
            return e;
        }
        return NULL;
    }
    if (l1 && l2) {
        carry = carry + l1->val + l2->val;
        l1->val = carry % 10;
        l1->next = addTwoNumbersCarry(l1->next, l2->next, carry/10);
        return l1;
    }
    if (l2) {
        l1 = l2;
    }
    if (carry) {
        carry += l1->val;
        l1->val = carry % 10;
        l1->next = addTwoNumbersCarry(l1->next, NULL, carry/10);
    }
    return l1;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addTwoNumbersCarry(l1, l2, 0);
}
