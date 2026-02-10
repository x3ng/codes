#include <vector>
#include <deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::deque<TreeNode*> nq;
        nq.push_back(root);
        std::vector<std::vector<int>> ans;
        int d = 1;
        while (!nq.empty()) {
            int cl = nq.size();
            std::vector<int> cln(cl);
            int p = d == 1 ? 0 : cl-1;
            while (cl--) {
                TreeNode* cn = nq.front();
                nq.pop_front();
                if (cn->left) {
                    nq.push_back(cn->left);
                }
                if (cn->right) {
                    nq.push_back(cn->right);
                }
                cln[p] = cn->val;
                p += d;
            }
            ans.push_back(cln);
            d *= -1;
        }
        return ans;
    }
};
