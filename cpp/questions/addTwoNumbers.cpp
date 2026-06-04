struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode dummy{};
        dummy.next = l1;
        ListNode* cur = &dummy;
        while (l1 && l2) {
            l1->val += l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            cur = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        cur->next = l1 ? l1 : l2;
        while (carry && cur->next) {
            cur = cur->next;
            cur->val += 1;
            carry = cur->val / 10;
            cur->val %= 10;
        }
        if (carry) {
            cur->next = new ListNode(1, nullptr);
        }
        return dummy.next;
    }
};
