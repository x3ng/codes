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
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<TreeNode*> nodes;
        auto getnode = [&](this auto&& getnode, TreeNode* node) -> void {
            if (node->left) {
                getnode(node->left);
            }
            nodes.push_back(node);
            if (node->right) {
                getnode(node->right);
            }
        };
        getnode(root);
        auto gentree = [&](this auto&& gentree, int s, int e) -> TreeNode* {
            if (s > e) {
                return nullptr;
            } else if (s == e) {
                TreeNode* cn = nodes[s];
                cn->left = nullptr;
                cn->right = nullptr;
                return cn;
            }
            int m = (e + s) / 2;
            TreeNode* cn = nodes[m];
            cn->left = gentree(s, m-1);
            cn->right = gentree(m+1, e);
            return cn;
        };
        return gentree(0, nodes.size()-1);
    }
};
