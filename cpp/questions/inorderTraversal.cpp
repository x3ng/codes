#include <bits/stdc++.h>
#include <vector>
#include <functional>

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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        // auto iT = [&](this auto&& iT, TreeNode* node) -> void {
        //     if (node == nullptr) {
        //         return;
        //     }
        //     iT(node->left);
        //     ans.push_back(node->val);
        //     iT(node->right);
        //     return;
        // };
        std::function<void(TreeNode*)> iT = [&](TreeNode* n) -> void {
            if (n == nullptr) {
                return;
            }
            iT(n->left);
            ans.push_back(n->val);
            iT(n->right);
            return;
        };
        iT(root);
        return ans;
    }
};
