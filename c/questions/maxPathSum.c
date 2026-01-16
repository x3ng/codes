/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dfsS(struct TreeNode* node, int* gMax) {
    if (node == NULL) {
        return 0;
    }
    int l = dfsS(node->left, gMax);
    l = MAX(l ,0);
    int r = dfsS(node->right, gMax);
    r = MAX(r, 0);
    int cgm = node->val + l + r;
    *gMax = MAX(*gMax, cgm);
    int ctm = node->val + MAX(l, r);
    return ctm;
}

int maxPathSum(struct TreeNode* root) {
    int gm = INT_MIN;
    dfsS(root, &gm);
    return gm;
}
