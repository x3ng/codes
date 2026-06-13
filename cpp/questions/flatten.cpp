#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        std::function<TreeNode*(TreeNode*)> io = [&](TreeNode* n) -> TreeNode* {
            if (n == nullptr) {
                return nullptr;
            }
            TreeNode* rn = n->right;
            TreeNode* le = io(n->left);
            if (le == nullptr) {
                le = n;
            }
            n->right = n->left;
            n->left = nullptr;
            TreeNode* re = io(rn);
            le->right = rn;
            return re ? re : le;
        };
        io(root);
    }
};
