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
private:
    bool symmetricLR(TreeNode* left, TreeNode* right) {
        if (left && right) {
            if (left->val == right->val) {
                return symmetricLR(left->left, right->right) && symmetricLR(left->right, right->left);
            }
        }
        if (!left && !right) {
            return true;
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root) {
            return symmetricLR(root->left, root->right);
        }
        return false;
    }
};
