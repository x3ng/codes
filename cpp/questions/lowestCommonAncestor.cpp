/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr || root==p || root==q) {
            return root;
        }
        TreeNode* lf = lowestCommonAncestor(root->left, p, q);
        TreeNode* rf = lowestCommonAncestor(root->right, p, q);
        if (lf && rf) {
            return root;
        }
        return lf ? lf : rf;
//        TreeNode* ans = nullptr;
//        auto dfs = [&](this auto&& dfs, TreeNode* node, bool* fp, bool* fq) -> void {
//            if (ans != nullptr) {
//                return;
//            }
//            if (node == nullptr) {
//                return;
//            }
//            bool cfp = false;
//            bool cfq = false;
//            dfs(node->left, &cfp, &cfq);
//            dfs(node->right, &cfp, &cfq);
//            if (node == p) {
//                cfp = true;
//            } else if (node == q) {
//                cfq = true;
//            }
//            if (cfp && cfq && ans == nullptr) {
//                ans = node;
//            }
//            *fp |= cfp;
//            *fq |= cfq;
//        };
//        bool dq = false;
//        bool dp = false;
//        dfs(root, &dq, &dp);
//        return ans;
    }
};
