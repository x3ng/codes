/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool nodeExist(struct TreeNode* root, int* level, int* nid) {
    int bs = 1 << (*level - 1);
    struct TreeNode* node = root;
    while (bs) {
        if (bs & *nid) {
            node = node->right;
        } else {
            node = node->left;
        }
        bs >>= 1;
    }
    return node != NULL;
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int level = 0;
    struct TreeNode* node = root;
    while (node->left) {
        node = node->left;
        level++;
    }
    int minn = 1 << level;
    int maxn = (1 << (level + 1)) - 1;
    while (minn < maxn) {
        int midn = (minn + maxn + 1) / 2;
        if (nodeExist(root, &level, &midn)) {
            minn = midn;
        } else {
            maxn = midn - 1;
        }
    }
    return minn;
}
