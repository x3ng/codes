#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int ll = 0;
        ListNode* cn = head;
        while (cn) {
            cn = cn->next;
            ++ll;
        }
        int hl = ll / 2;
        std::vector<int> pl(hl);
        while (hl--) {
            pl[hl] = head->val;
            head = head->next;
        }
        head = ll%2 ? head->next : head;
        for (int i=0; i<pl.size(); ++i) {
            if (head->val != pl[i]) {
                return false;
            }
            head = head->next;
        }
        return true;
    }
};
