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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        std::function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {       
            if (node == nullptr) {
                return 0;
            }
            int l = std::max(dfs(node->left), 0);
            int r = std::max(dfs(node->right), 0);
            maxSum = std::max(maxSum, node->val+l+r);
            return std::max(l, r) + node->val;
        };
        dfs(root);
        return maxSum;
    }
};
