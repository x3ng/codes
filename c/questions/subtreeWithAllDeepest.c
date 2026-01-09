/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int deepthS(struct TreeNode* root, int depth, int* maxdepth, struct TreeNode** mdp) {
    if (root == NULL) {
        if (depth > *maxdepth) {
            *maxdepth = depth;
        }
        return depth;
    }
    int ld = deepthS(root->left, depth+1, maxdepth, mdp);
    int rd = deepthS(root->right, depth+1, maxdepth, mdp);
    if (ld==*maxdepth && rd==*maxdepth) {
        *mdp = root;
    }
    return MAX(ld, rd);
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    int maxdepth = 0;
    struct TreeNode* mdp = root;
    deepthS(root, 0, &maxdepth, &mdp);
    return mdp;
}
