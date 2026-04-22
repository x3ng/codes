#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    class wordTree {
        struct wtNode {
            // bool end = false;
            wtNode* child[26] = {nullptr};
        };
    public:
        wtNode* rt;

        wordTree() {
            rt = new wtNode();
        }

        void insert(std::string s) {
            wtNode* cn = rt;
            for (int p=0; p<s.size(); ++p) {
                int cp = s[p] - 'a';
                if (cn->child[cp] == nullptr) {
                    cn->child[cp] = new wtNode();
                }
                cn = cn->child[cp];
            }
            // cn->end = true;
        }

        bool diffSearch(wtNode* sn, const std::string& s, int p, int diff) {
            if (sn == nullptr || diff < 0) {
                return false;
            }
            if (p >= s.size()) {
                return true;
            }
            int cp = s[p] - 'a';
            bool res = false;
            for (const auto c: sn->child) {
                res |= diffSearch(c, s, p+1, sn->child[cp] ? diff : diff-1);
                if (res) {
                    return true;
                }
            }
            return false;
        }
    };

public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        wordTree wt;

        for (const auto& d: dictionary) {
            wt.insert(d);
        }

        std::vector<std::string> ans;
        for (const auto& q: queries) {
            if (wt.diffSearch(wt.rt, q, 0, 2)) {
                ans.push_back(q);
            }
        }
        return ans;
    }
};
