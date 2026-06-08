struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* fn = &dummy;
        ListNode* en = fn;
        for (int i=0; i<k; ++i) {
            fn = fn->next;
        }
        bool nr = fn ? true : false;
        while (nr) {
            ListNode* ne = en->next;
            ListNode* nf = fn->next;
            ListNode* cur = nullptr;
            ListNode* nxt = en->next;
            en->next = fn;
            for (int i=0; i<k; ++i) {
                ListNode* nnxt = nxt->next;
                nxt->next = cur;
                cur = nxt;
                nxt = nnxt;
                fn = fn ? fn->next : nullptr;
            }
            nr = fn ? true : false;
            en = ne;
            en->next = nf;
        }
        return dummy.next;
    }
};
