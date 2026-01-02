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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        std::stack<ListNode*> st;
        for (int p=k; p>0; p--) {
            if (cur == nullptr) {
                return head;
            }
            st.push(cur);
            cur = cur->next;
        }
        ListNode* nh = st.top();
        ListNode* nt = nh;
        st.pop();
        while (!st.empty()) {
            nt->next = st.top();
            st.pop();
            nt = nt->next;
        }
        nt->next = reverseKGroup(cur, k);
        return nh;
    }
};
