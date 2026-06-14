#include <functional>
#include <vector>

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
    int pathSum(TreeNode* root, int targetSum) {
        std::vector<long long> ps = {0};
        int ans = 0;
        std::function<void(TreeNode*)> pS = [&](TreeNode* n) -> void {
            if (n == nullptr) {
                return;
            }
            long long sps = ps.back() + n->val - targetSum;
            for (int i=0; i<ps.size(); ++i) {
                if (sps == ps[i]) {
                    ++ans;
                }
            }
            ps.push_back(sps+targetSum);
            pS(n->left);
            pS(n->right);
            ps.pop_back();
        };
        pS(root);
        return ans;
    }
};
