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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> bool {
            if (node == nullptr) {
                return false;
            }
            if (dfs(node->left)) {
                return true;
            }
            if (--k == 0) {
                ans = node->val;
                return true;
            }
            return dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};
