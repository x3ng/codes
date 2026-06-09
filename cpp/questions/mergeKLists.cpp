#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int cl = lists.size();
        while (cl > 1) {
            int p = 0;
            for (; 2*p<cl-1; ++p) {
                lists[p] = mergeList(lists[2*p], lists[2*p+1]);
            }
            if (cl % 2) {
                lists[p++] = lists[2*p];
            }
            cl = p;
        }
        return cl ? lists[0] : nullptr;
    }
};
