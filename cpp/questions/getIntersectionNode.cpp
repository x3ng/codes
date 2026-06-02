#include <algorithm>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* cA = headA;
        ListNode* cB = headB;
        while (cA && cB) {
            cA = cA->next;
            cB = cB->next;
        }
        if (cB == nullptr) {
            std::swap(headA, headB);
            std::swap(cA, cB);
        }
        while (cB) {
            cB = cB->next;
            headB = headB->next;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
