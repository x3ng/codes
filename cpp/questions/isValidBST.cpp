#include <bits/stdc++.h>
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
    bool isValidBST(TreeNode* root) {
        long long pre = LONG_LONG_MIN;
        std::function<bool(TreeNode*)> io = [&](TreeNode* n) -> bool {                
            if (n == nullptr) {
                return true;
            }
            if (!io(n->left)) {
                return false;
            }
            if (n->val <= pre) {
                return false;
            }
            pre = n->val;
            return io(n->right);
        };
        return io(root);
    }
};
