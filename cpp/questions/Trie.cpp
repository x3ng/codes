#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    struct TNode {
        std::vector<TNode*> child;
        bool is_end;

        TNode() {
            child.resize(26);
            is_end = false;
        }
    };

    TNode* root;

public:
    Trie() {
        root = new TNode();     
    }

    TNode* _toEnd(string& s) {
        TNode* cur = root;
        for (char c: s) {
            TNode* nn = cur->child[c-'a'];
            if (nn == nullptr) {
                return nullptr;
            }
            cur = nn;
        }
        return cur;
    }
    
    void insert(string word) {
        TNode* cur = root;
        for (char c: word) {
            if (cur->child[c-'a'] == nullptr) {
                cur->child[c-'a'] = new TNode();
            }
            cur = cur->child[c-'a'];
        }
        cur->is_end = true;
    }
    
    bool search(string word) {
        TNode* en = _toEnd(word);
        if (en == nullptr) {
            return false;
        }
        return en->is_end;
    }
    
    bool startsWith(string prefix) {
        TNode* en = _toEnd(prefix);
        return en ? true : false;
    }
};
