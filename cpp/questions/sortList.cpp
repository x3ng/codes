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
private:
    ListNode* midNode(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head->next;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }

    ListNode* mergeLN(ListNode* ln1, ListNode* ln2) {
        ListNode dummy = ListNode();
        ListNode* cur = &dummy;
        while (ln1 && ln2) {
            if (ln1->val < ln2->val) {
                cur->next = ln1;
                ln1 = ln1->next;
            } else {
                cur->next = ln2;
                ln2 = ln2->next;
            }
            cur = cur->next;
        }
        cur->next = ln1 ? ln1 : ln2;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head && head->next) {
            ListNode* mn = midNode(head);
            ListNode* nn = mn->next;
            mn->next = nullptr;
            return mergeLN(sortList(head), sortList(nn));
        } else {
            return head;
        }
    }
};
