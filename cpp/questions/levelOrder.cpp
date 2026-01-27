#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::vector<std::vector<int>> ans;
        std::queue<TreeNode*> ln;
        ln.push(root);
        while (!ln.empty()) {
            std::vector<int> cln;
            int cls = ln.size();
            while (cls--) {
                TreeNode* cn = ln.front();
                if (cn->left) {
                    ln.push(cn->left);
                }
                if (cn->right) {
                    ln.push(cn->right);
                }
                ln.pop();
                cln.push_back(cn->val);
            }
            ans.push_back(cln);
        }
        return ans;
    }
};
