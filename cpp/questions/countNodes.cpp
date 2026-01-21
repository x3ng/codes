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
private:
    bool nodeExist(TreeNode* root, int& level, int& nid) {
        int dc = 1 << (level - 1);
        TreeNode* node = root;
        while (dc) {
            if (dc & nid) {
                node = node->right;
            } else {
                node = node->left;
            }
            dc >>= 1;
        }
        return node != nullptr;
    }
    
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        while (node->left) {
            level++;
            node = node->left;
        }
        int minn = 1 << level;
        int maxn = (1 << (level + 1)) - 1;
        while (minn < maxn) {
            int midn = (minn + maxn + 1) / 2;
            if (nodeExist(root, level, midn)) {
                minn = midn;
            } else {
                maxn = midn - 1;
            }
        }
        return minn;
    }
};
