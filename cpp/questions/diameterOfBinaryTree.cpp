#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        std::function<int(TreeNode*)> dfs = [&ans, &dfs](TreeNode* n) -> int {
            if (n == nullptr) {
                return 0;
            }
            int ld = dfs(n->left);
            int rd = dfs(n->right);
            ans = std::max(ans, ld+rd);
            return std::max(ld, rd)+1;
        };
        dfs(root);
        return ans;
    }
};
