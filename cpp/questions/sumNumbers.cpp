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
    int sumNumbers(TreeNode* root) {
        auto dfs = [](this auto&& dfs, int pres, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            pres = pres*10 + node->val;
            int lrs = dfs(pres, node->left) + dfs(pres, node->right);
            if (lrs == 0) {
                return pres;
            } else {
                return lrs;
            }
        };
        return dfs(0, root);
    }
};
