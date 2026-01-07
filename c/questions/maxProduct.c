/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int treeSum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int sum = root->val + treeSum(root->left) + treeSum(root->right);
    return sum;
}

int calAns(struct TreeNode* root, int* cd, int* hts, int* ts) {
    if (root == NULL) {
        return 0;
    }
    int sum = root->val + calAns(root->left, cd, hts, ts) + calAns(root->right, cd, hts, ts);
    int cds;
    if (sum < *hts+1) {
        cds = *hts - sum;
    } else {
        cds = *hts + sum - *ts;
    }
    if (cds < *cd) {
        *cd = cds;
    }
    return sum;
}

int maxProduct(struct TreeNode* root) {
    const int MOD = 1000000007;
    int ts = treeSum(root);
    int hts = ts / 2;
    int cd = hts;
    calAns(root, &cd, &hts, &ts);
    long long ans = (hts - cd) * (long long)(ts + cd - hts);
    ans %= MOD;
    return ans;
}
