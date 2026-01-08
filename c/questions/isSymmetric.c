/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool symmetricLR(struct TreeNode* left, struct TreeNode* right) {
    if (left && right) {
        if (left->val == right->val) {
            return symmetricLR(left->left, right->right) && symmetricLR(left->right, right->left);
        }
        return false;
    }
    if (!left && !right) {
        return true;
    }
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return symmetricLR(root->left, root->right);
}
