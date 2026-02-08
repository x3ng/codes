/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        auto height = [](this auto&& height, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            int l = height(node->left);
            int r = height(node->right);
            if (l==-1 || r==-1 || std::abs(l-r)>1) {
                return -1;
            }
            return std::max(l, r) + 1;
        };
        return height(root) != -1;
    }
};
