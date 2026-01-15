/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumTN(int pres, struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    pres = pres*10 + node->val;
    int lrs = sumTN(pres, node->left) + sumTN(pres, node->right);
    if (lrs == 0) {
        return pres;
    } else {
        return lrs;
    }
}

int sumNumbers(struct TreeNode* root) {
    return sumTN(0, root);
}
