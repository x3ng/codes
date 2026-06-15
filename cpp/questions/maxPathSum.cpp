#include <bits/stdc++.h>
#include <functional>

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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        std::function<int(TreeNode*)> mp = [&](TreeNode* n) -> int {
            if (n == nullptr) {
                return 0;
            }
            int l = std::max(mp(n->left), 0);
            int r = std::max(mp(n->right), 0);
            ans = std::max(ans, n->val+l+r);
            return n->val+std::max(l, r);
        };
        mp(root);
        return ans;
    }
};
