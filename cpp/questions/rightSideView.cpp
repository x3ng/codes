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
    vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> tmp;
        if (root) {
            tmp.push(root);
        } else {
            return {};
        }
        std::vector<int> ans;
        while(!tmp.empty()) {
            int ls = tmp.size();
            ans.push_back(tmp.back()->val);
            while (ls--) {
                TreeNode* cn = tmp.front();
                tmp.pop();
                if (cn->left) {
                    tmp.push(cn->left);
                }
                if (cn->right) {
                    tmp.push(cn->right);
                }
            }
        }
        return ans;
    }
};
