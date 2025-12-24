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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
        if (l1 && l2) {
            l1->val = l1->val + l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            l1->next = addTwoNumbers(l1->next, l2->next, carry);
            return l1;
        } else {
            if (carry) {
                if (l1) {
                    l1->val = l1->val + carry;
                    carry = l1->val / 10;
                    l1->val %= 10;
                    l1->next = addTwoNumbers(l1->next, nullptr, carry);
                    return l1;
                } else if (l2) {
                    l2->val = l2->val + carry;
                    carry = l2->val / 10;
                    l2->val %= 10;
                    l2->next = addTwoNumbers(l2->next, nullptr, carry);
                    return l2;
            
                } else {
                    return new ListNode(1);
                }
            } else {
                return l1 ? l1 : l2;
            }
        }
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }
};
