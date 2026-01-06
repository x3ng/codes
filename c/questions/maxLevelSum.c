/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
    int mas = INT_MIN;
    int level = 1;
    int ans = 0;
    int rns = 1;
    struct TreeNode** rn = (struct TreeNode**) malloc(sizeof(struct TreeNode*) * rns);
    rn[0] = root;
    int le = 0;
    int ce = 0;
    int ls = 0;
    while (ls <= le) {
        int ts = 0;
        rns += (le-ls+1) * 2;
        rn = (struct TreeNode**) realloc(rn, sizeof(struct TreeNode*) * rns);
        struct TreeNode* tmp;
        while (ls <= ce) {
            tmp = rn[ls];
            ts += tmp->val;
            if (tmp->left) {
                rn[++le] = tmp->left;
            }
            if (tmp->right) {
                rn[++le] = tmp->right;
            }
            ls++;
        }
        ce = le;
        if (ts > mas) {
            mas = ts;
            ans = level;
        }
        level++;
    }
    free(rn);
    return ans;
}
