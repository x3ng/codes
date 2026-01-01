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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        std::stack<ListNode*> nst;
        ListNode* dummy = new ListNode(0, head);
        head = dummy;
        int p = 1;
        while (p < left) {
            head = head->next;
            p++;
        }
        ListNode* rs = head;
        head = head->next;
        while (p < right) {
            nst.push(head);
            p++;
            head = head->next;
        }
        rs->next = head;
        rs = head;
        head = head->next ? head->next : nullptr;
        while (!nst.empty()) {
            rs->next = nst.top();
            nst.pop();
            rs = rs->next;
        }
        rs->next = head;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
