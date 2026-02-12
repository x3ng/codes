/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    std::unordered_map<Node*, Node*> oc;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (oc.find(node) != oc.end()) {
            return oc[node];
        }
        Node* ccn = new Node(node->val);
        oc[node] = ccn;
        for (const auto& n: node->neighbors) {
            ccn->neighbors.emplace_back(cloneGraph(n));
        }
        return ccn;
    }
};
