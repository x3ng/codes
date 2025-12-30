/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    while (cur) {
        struct Node* ist = (struct Node*)malloc(sizeof(struct Node));
        ist->val = cur->val;
        ist->next = cur->next;
        cur->next = ist;
        cur = ist->next;
    }
    struct Node* asi;
    cur = head;
    while (cur) {
        asi = cur->next;
        asi->random = cur->random==NULL ? NULL : curr->random->next;
        cur = asi->next;
    }
    struct Node* ans = head->next;
    cur = head;
    asi = cur->next;
    while (asi->next) {
        cur->next = asi->next;
        asi->next = cur->next->next;
        cur = cur->next;
        asi = asi->next;
    }
    cur->next = NULL;
    return ans;
}
