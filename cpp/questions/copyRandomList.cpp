/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* curr = head;
        while (curr) {
            Node* inst = new Node(curr->val);
            inst->next = curr->next;
            curr->next = inst;
            curr = inst->next;
        }
        curr = head;
        Node* tmp;
        while (curr) {
            tmp = curr->next;
            tmp->random = curr->random==nullptr ? nullptr : curr->random->next;
            curr = tmp->next;
        }
        Node* ans = head->next;
        curr = head;
        tmp = head->next;
        while (tmp->next) {
            curr->next = tmp->next;
            tmp->next = curr->next->next;
            curr = curr->next;
            tmp = tmp->next;
        }
        curr->next = nullptr;
        return ans;
    }
};
