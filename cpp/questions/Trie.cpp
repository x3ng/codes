class Trie {
private:
    struct Node {
        Node* child[26] = {nullptr};
        bool is_end = false;
    };
    Node* root = nullptr;
public:
    Trie() {
        root = new Node(); 
    }
    
    void insert(string word) {
        int ws = word.size();
        Node* cn = root;
        for (int p=0; p<ws; p++) {
            int cp = word[p] - 'a';
            if (cn->child[cp] == nullptr) {
                cn->child[cp] = new Node();
            }
            cn = cn->child[cp];
        }
        cn->is_end = true;
    }
    
    bool search(string word) {
        int ws = word.size();
        Node* cn = root;
        for (int p=0; p<ws; p++) {
            int cp = word[p] - 'a';
            if (cn->child[cp] == nullptr) {
                return false;
            }
            cn = cn->child[cp];
        }
        return cn->is_end ? true : false;
    }
    
    bool startsWith(string prefix) {
        int ws = prefix.size();
        Node* cn = root;
        for (int p=0; p<ws; p++) {
            int cp = prefix[p] - 'a';
            if (cn->child[cp] == nullptr) {
                return false;
            }
            cn = cn->child[cp];
        }
        return true;
    }
};
