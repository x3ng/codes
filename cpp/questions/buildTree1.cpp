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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        std::map<int, int> inm;
        for (int p=0; p<inorder.size(); p++) {
            inm[inorder[p]] = p;
        }
        auto build = [&](this auto&& build, int ine, int poste, int len) -> TreeNode* {
            if (len == 0) {
                return nullptr;
            }
            int ip = inm[postorder[poste]];
            int rl = ine - ip;
            return new TreeNode(postorder[poste], build(ip-1, poste-rl-1, len-rl-1), build(ine, poste-1, rl));
        };
        return build(inorder.size()-1, postorder.size()-1, inorder.size());
    }
};
