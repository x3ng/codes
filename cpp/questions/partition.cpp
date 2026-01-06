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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0, head);
        ListNode* inn = &dummy;
        ListNode* cur;
        while (inn->next && inn->next->val < x) {
            inn = inn->next;
        }
        head = inn->next;
        if (head == nullptr) {
            return dummy.next;
        }
        cur = head;
        while (cur) {
            if (cur->next && cur->next->val < x) {
                ListNode* tmp = cur;
                cur = cur->next;
                while (cur->next && cur->next->val < x) {
                    cur = cur->next;
                }
                inn->next = tmp->next;
                tmp->next = cur->next;
                tmp = cur->next;
                cur->next = head;
                inn = cur;
                cur = tmp;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
