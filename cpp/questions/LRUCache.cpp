// #include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* pre;
        Node* nxt;

        Node(int k, int v, Node* p, Node* n) : key(k), val(v), pre(p), nxt(n) {}
    };

    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> hm;
    int cap;

    void freshNode(Node* n) {
        n->nxt->pre = n->pre;
        n->pre->nxt = n->nxt;
        n->nxt = head->nxt;
        n->pre = head;
        n->nxt->pre = n;
        head->nxt = n;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0, nullptr, nullptr);
        tail = new Node(0, 0, head, nullptr);
        head->nxt = tail;
    }
    
    int get(int key) {
        auto it = hm.find(key);
        if (it != hm.end()) {
            Node* cn = it->second;
            freshNode(cn);
            return cn->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            head->nxt->val = value;
        } else if (cap) {
            --cap;
            Node* nn = new Node(key, value, head, head->nxt);
            head->nxt->pre = nn;
            head->nxt = nn;
            hm[key] = nn;
        } else {
            Node* on = tail->pre;
            int ok = on->key;
            hm.erase(ok);
            hm[key] = on;
            freshNode(on);
            on->key = key;
            on->val = value;
        }
    }
};
