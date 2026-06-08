struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* cur = &dummy;
        while (cur->next && cur->next->next) {
            ListNode* cn = cur->next;
            ListNode* cnn = cn->next;
            cn->next = cnn->next;
            cnn->next = cn;
            cur->next = cnn;
            cur = cn;
        }
        return dummy.next;
    }
};
