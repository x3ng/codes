#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    void reverse(ListNode* b, ListNode* e) {
        ListNode* p = nullptr;
        while (p != e) {
            ListNode* n = b->next;
            b->next = p;
            p = b;
            b = n;
        }
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head->next;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode* ns = s->next;
        reverse(head, s);
        ListNode* ps = f ? s : s->next;
        while (ps && ns) {
            if (ps->val != ns->val) {
                return false;
            }
            ps = ps->next;
            ns = ns->next;
        }
        return true;
    }
};
