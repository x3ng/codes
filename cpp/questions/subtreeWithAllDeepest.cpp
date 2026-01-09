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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxdepth = 0;
        TreeNode* deepestPNode = root;
        auto dfs = [&](this auto&& dfs, TreeNode* root, int depth) -> int {
            if (!root) {
                if (depth > maxdepth) {
                    maxdepth = depth;
                }
                return depth;
            }
            int ld = dfs(root->left, depth+1);
            int rd = dfs(root->right, depth+1);
            if (ld==maxdepth && rd==maxdepth) {
                deepestPNode = root;
            }
            return std::max(ld, rd);
        };
        dfs(root, 0);
        return deepestPNode;
    }
};
