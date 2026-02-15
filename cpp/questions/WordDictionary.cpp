class WordDictionary {
private:
    struct Node {
        Node* child[26] = {nullptr};
        bool isEnd = false;

        Node() {};
    };

    Node* root = nullptr;

    void insert(Node* node, std::string& word) {
        Node* cn = node;
        for (const char& c: word) {
            int cp = c - 'a';
            if (cn->child[cp] == nullptr) {
                cn->child[cp] = new Node();
            }
            cn = cn->child[cp];
        }
        cn->isEnd = true;
    }

    bool dfs(Node* node, std::string& word, int wp) {
        if (wp == word.size()) {
            return node->isEnd;
        }
        Node* cn = node;
        for (; wp < word.size(); wp++) {
            char c = word[wp];
            if ('a' <= c && c <= 'z') {
                int cp = c - 'a';
                if (cn->child[cp] == nullptr) {
                    return false;
                }
                cn = cn->child[cp];
            } else if (c == '.') {
                for (const auto& n: cn->child) {
                    if (n!=nullptr && dfs(n, word, wp+1)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return cn->isEnd;
    }

public:
    WordDictionary() {
        root = new Node();        
    }
    
    void addWord(string word) {
        insert(root, word);     
    }
    
    bool search(string word) {
        return dfs(root, word, 0);    
    }
};
