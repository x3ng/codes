#include <bits/stdc++.h>

using namespace std;

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
        while (cA != cB) {
            cA = cA ? cA->next : headB;
            cB = cB ? cB->next : headA;
        }
        return cA;
    }
};
