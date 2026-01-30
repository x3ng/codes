#include <vector>
#include <string>
#include <climits>

using namespace std;

struct Trie {
    Trie* child[26];
    int id = -1;

    Trie() {
        for (int p=0; p<26; p++) {
            child[p] = nullptr;
        }
    }
};

int add(Trie* node, const std::string& s, int& index) {
    for (const auto& c: s) {
        int idx = c - 'a';
        if (node->child[idx] == nullptr) {
            node->child[idx] =  new Trie();
        }
        node = node->child[idx];
    }
    if (node->id == -1) {
        node->id = ++index;
    }
    return node->id;
}

void update(long long& cv, long long rv) {
    if (cv == -1 || cv > rv) {
        cv = rv;
    }
}

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        std::vector<std::vector<int>> rc(m*2, std::vector<int>(m*2, INT_MAX/2));
        Trie* root = new Trie();
        int nc = -1;
        for (int p=0; p<m; p++) {
            int oi = add(root, original[p], nc);
            int ci = add(root, changed[p], nc);
            rc[oi][ci] = std::min(rc[oi][ci], cost[p]);
            rc[oi][oi] = 0;
            rc[ci][ci] = 0;
        }
        for (int p=0; p<=nc; p++) {
            for (int r=0; r<=nc; r++) {
                for (int c=0; c<=nc; c++) {
                    int pc = rc[r][p] + rc[p][c];
                    rc[r][c] = std::min(rc[r][c], pc);
                }
            }
        }
        std::vector<long long> sc(n+1, -1);
        sc[0] = 0;
        for (int p=1; p<n+1; p++) {
            long long prec = sc[p-1];
            if (prec == -1) {
                continue;
            }
            if (source[p-1] == target[p-1]) {
                update(sc[p], prec);
            }
            Trie* sn = root;
            Trie* tn = root;
            for (int sp=p-1; sp<n; sp++) {
                sn = sn->child[source[sp]-'a'];
                tn = tn->child[target[sp]-'a'];
                if (!sn || !tn) {
                    break;
                }
                if (sn->id!=-1 && tn->id!=-1 && rc[sn->id][tn->id]!=INT_MAX/2) {
                    update(sc[sp+1], prec+rc[sn->id][tn->id]);
                }
            }
        }
        return sc[n];
    }
};
