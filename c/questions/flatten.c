/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* pft(struct TreeNode* node) {
    struct TreeNode* rn = node->right;
    struct TreeNode* tail = node;
    if (node->left) {
        node->right = node->left;
        tail = pft(node->left);
        node->left = NULL;
    }
    if (rn) {
        tail->right = rn;
        tail = pft(rn);
    }
    return tail;
}

void flatten(struct TreeNode* root) {
    if (root) {
        pft(root);
    } else {
        return;
    }
}
