class Solution {
private:
    struct TrieNode {
        std::string word = "";
        std::map<char, TrieNode*> child;
        TrieNode() {
        }
    };

    void insertTrie(TrieNode* node, std::string word) {
        TrieNode* cn = node;
        for (auto& c: word) { 
            if (cn->child[c] == nullptr) {
                cn->child[c] = new TrieNode();
            }
            cn = cn->child[c];
        }
        cn->word = word;
    }

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
        int rs = board.size();
        int cs = board[0].size();
        TrieNode * trie = new TrieNode();
        vector<string> ans;
        for (auto& word: words){
            insertTrie(trie, word);
        }
        auto dfs = [&](this auto&& dfs, TrieNode* node, int r, int c) -> void {
            char cc = board[r][c];
            if (!node->child.count(cc)) {
                return;
            }
            board[r][c] = '0';
            node = node->child[cc];
            if (node->word.size()) {
                ans.push_back(node->word);
                node->word = "";
            }
            for (auto d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr>=0 && nr<rs && nc>=0 && nc<cs && board[nr][nc]!='0') {
                    dfs(node, nr, nc);
                }
            }
            board[r][c] = cc;
            if (node->child.empty()) {
                node->child.erase(cc);
            }
            return;
        };
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(trie, i, j);
            }
        }        
        return ans;        
    }
};
