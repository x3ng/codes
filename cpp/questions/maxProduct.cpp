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
    int maxProduct(TreeNode* root) {
        std::vector<int> ts;
        auto dfs = [&] (this auto&& dfs, TreeNode* root) -> int {
            if (root == nullptr) {
                return 0;
            }
            int sum = root->val + dfs(root->left) + dfs(root->right);
            ts.push_back(sum);
            return sum;
        };
        long long total = dfs(root);
        long long ans = 0;
        for (int& cs : ts) {
            ans = std::max(ans, cs*(total-cs));
        }
        return ans%1'000'000'007;
    }
};
