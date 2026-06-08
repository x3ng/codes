//#include <bits/stdc++.h>
#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> hm; 
        Node* dummy = new Node(0);
        Node* cur = dummy;
        while (head) {
            cur->next = new Node(head->val);
            hm[head] = cur->next;
            cur = cur->next;
            cur->random = head->random;
            head = head->next;
        }
        cur = dummy->next;
        while (cur) {
           cur->random = hm[cur->random];
           cur = cur->next;
        }
        return dummy->next;
    }
};
