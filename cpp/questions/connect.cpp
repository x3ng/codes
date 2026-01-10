/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        std::vector<Node*> lrn;
        auto rdfs = [&](this auto&& rdfs, Node* n, int level) -> void {
            if (n == nullptr) {
                return;
            }
            if (level >= lrn.size()) {
                lrn.push_back(n);
            } else {
                n->next = lrn[level];
                lrn[level] = n;
            }
            rdfs(n->right, level+1);
            rdfs(n->left, level+1);
            return;
        };
        rdfs(root, 0);
        return root;
    }
};
