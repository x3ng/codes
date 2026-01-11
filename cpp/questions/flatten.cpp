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
    void flatten(TreeNode* root) {
        auto pft = [](this auto&& pft, TreeNode* node) -> TreeNode* {
            TreeNode* tail = node;
            TreeNode* rn = node->right;
            if (node->left) {
                node->right = node->left;
                tail = pft(node->left);
                node->left = nullptr;
            }
            if (rn) {
                tail->right = rn;
                tail = pft(rn);
            }
            return tail;
        };
        if (root) {
            pft(root);
        } else {
            return;
        }
    }
};
