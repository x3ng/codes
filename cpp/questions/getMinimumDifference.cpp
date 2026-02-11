#include <vector>
#include <climits>

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

using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* pre = nullptr;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (node == nullptr) {
                return;
            }
            dfs(node->left);
            ans = pre ? std::min(ans, node->val-pre->val) : ans;
            pre = node;
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};
