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
    int sumRootToLeaf(TreeNode* root) {
        auto gn = [](this auto&& gn, TreeNode* node, int pv) -> int {
            int nv = (pv << 1) + node->val;
            int cv = node->left ? gn(node->left, nv) : 0;
            cv += node->right ? gn(node->right, nv) : 0;
            return cv == 0 ? nv : cv;
        };
        return gn(root, 0);
    }
};
