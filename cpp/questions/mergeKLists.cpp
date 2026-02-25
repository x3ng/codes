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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) -> bool {
            return a->val > b->val;
        };
        priority_queue<ListNode*, std::vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(cmp);
        for (const auto& ln: lists) {
            if (ln) {
                pq.push(ln);
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* cn = dummy;
        while (!pq.empty()) {
            ListNode* mn = pq.top();
            pq.pop();
            cn->next = mn;
            cn = cn->next;
            if (mn->next) {
                pq.push(mn->next);
            }
        }
        return dummy->next;
    }
};
