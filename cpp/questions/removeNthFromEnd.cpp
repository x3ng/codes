/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* n1b = &dummy;
        ListNode* cur = &dummy;
        while (n-- >= 0) {
            cur = cur->next;
        }
        while (cur) {
            cur = cur->next;
            n1b = n1b->next;
        }
        ListNode* ncn = n1b->next->next;
        delete n1b->next;
        n1b->next = ncn;
        return dummy.next;
    }
};
