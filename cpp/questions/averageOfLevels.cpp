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
    vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> ln;                       
        std::vector<double> ans;
        ln.push(root);
        while (!ln.empty()) {
            int cls = ln.size();
            double cs = 0;
            for (int p=0; p<cls; p++) {
                TreeNode* cn = ln.front();
                if (cn->left) {
                    ln.push(cn->left);
                }
                if (cn->right) {
                    ln.push(cn->right);
                }
                ln.pop();
                cs += cn->val;
            }
            ans.push_back(cs / cls);
        }
        return ans;
    }
};
