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
    int maxLevelSum(TreeNode* root) {
        int mas = INT_MIN;
        std::vector<TreeNode*> tnl = { root };
        int level = 1;
        int ans;
        while (!tnl.empty()) {
            auto tmp = std::move(tnl);
            int ts = 0;
            for (auto& n : tmp) {
                ts += n->val;
                if (n->left) {
                    tnl.push_back(n->left);
                }
                if (n->right) {
                    tnl.push_back(n->right);
                }
            }
            if (ts > mas) {
                mas = ts;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
