#include <bits/stdc++.h>

using namespace std;

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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ans;
        std::function<void(TreeNode*, int)> io = [&](TreeNode* n, int d) -> void {
            if (n == nullptr) {
                return;
            }
            if (d > ans.size()) {
                ans.push_back(n->val);
            }
            io(n->right, d+1);
            io(n->left, d+1);
        };
        io(root, 1);
        return ans;
    }
};
