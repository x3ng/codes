struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fn = head;
        ListNode* en = &dummy;
        while (n--) {
            fn = fn->next;
        }
        while (fn) {
            fn = fn->next;
            en = en->next;
        }
        en->next = en->next->next;
        return dummy.next;
    }
};
