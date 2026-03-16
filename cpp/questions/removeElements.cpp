struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        head = &dummy;
        while (head) {
            ListNode* tmp = head->next;
            while (tmp && tmp->val == val) {
                tmp = tmp->next;
            }
            head->next = tmp;
            head = head->next;
        }
        return dummy.next;
    }
};
