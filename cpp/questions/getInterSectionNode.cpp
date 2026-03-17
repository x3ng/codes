struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* cur = headA;
        while (cur) {
            ++lenA;
            cur = cur->next;
        }
        cur = headB;
        while (cur) {
            ++lenB;
            cur = cur->next;
        }
        ListNode* ano;
        int df = lenA - lenB;
        if (lenA > lenB) {
            cur = headA;
            ano = headB;
        } else {
            cur = headB;
            ano = headA;
            df = -df;
        }     
        while (df--) {
            cur = cur->next;
        }
        while (cur && ano) {
            if (cur == ano) {
                return cur;
            }
            cur = cur->next;
            ano = ano->next;
        }
        return nullptr;
    }
};
