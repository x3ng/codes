#include <bits/stdc++.h>
#include <vector>
#include <deque>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> ans;
        std::deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int cl = dq.size();
            std::vector<int> cv;
            cv.reserve(cl);
            while (cl--) {
                TreeNode* cn = dq.front();
                dq.pop_front();
                cv.push_back(cn->val);
                if (cn->left) {
                    dq.push_back(cn->left);
                }
                if (cn->right) {
                    dq.push_back(cn->right);
                }
            }
            ans.emplace_back(cv);
        }
        return ans;
    }
};
