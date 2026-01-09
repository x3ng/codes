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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto build = [](this auto&& build, std::vector<int>& preorder, int pres, std::vector<int>& inorder, int ins, int len) -> TreeNode* {
            if (len == 0) {
                return nullptr;
            }
            int ip;
            for (ip=ins; ip<ins+len-1; ip++) {
                if (inorder[ip] == preorder[pres]) {
                    break;
                }
            }
            int ll = ip - ins;
            int rl = ins + len - ip - 1;
            return new TreeNode(inorder[ip], build(preorder, pres+1, inorder, ins, ip-ins), build(preorder, pres+ll+1, inorder, ip+1, ins+len-ip-1));
        };
        return build(preorder, 0, inorder, 0, inorder.size());
    }
};
