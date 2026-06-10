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
    bool isSymmetric(TreeNode* root) {
        std::function<bool(TreeNode*, TreeNode*)> cLR = [&](TreeNode* l, TreeNode* r) -> bool {
            if (l && r) {
                return l->val==r->val ? cLR(l->left, r->right) && cLR(l->right, r->left) : false;
            }
            if (l==nullptr && r == nullptr) {
                return true;
            }
            return false;
        };
        return root ? cLR(root->left, root->right) : true;
    }
};
