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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        std::function<void(TreeNode*)> io = [&](TreeNode* n) -> void {
            if (n == nullptr) {
                return;
            }
            io(n->left);
            if (--k == 0) {
                ans = n->val;
                return;
            }
            io(n->right);
        };
        io(root);
        return ans;
    }
};
