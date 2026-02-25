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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto bbst = [&](this auto&& bbst, int l, int r) -> TreeNode* {
            if (l > r) {
                return nullptr;
            }
            int m = (l + r) / 2;
            TreeNode* cn = new TreeNode(nums[m]);
            cn->left = bbst(l, m-1);
            cn->right = bbst(m+1, r);
            return cn;
        };
        return bbst(0, nums.size()-1);
    }
};
