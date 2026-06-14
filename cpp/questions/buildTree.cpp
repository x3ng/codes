#include <functional>
#include <unordered_map>
#include <vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pp = 0;
        std::unordered_map<int, int> ihm;
        for (int p=0; p<inorder.size(); ++p) {
            ihm[inorder[p]] = p;
        }
        std::function<TreeNode*(int, int)> bt = [&](int il, int ir) -> TreeNode* {
            int nv = preorder[pp++];
            TreeNode* tn = new TreeNode(nv);
            int ip = ihm[nv];
            tn->left = ip==il ? nullptr : bt(il, ip-1);
            tn->right = ip==ir ? nullptr : bt(ip+1, ir);
            return tn;
        };
        return bt(0, inorder.size()-1);
    }
};
