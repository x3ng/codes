/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* build(int* preorder, int pres, int* inorder, int ins, int len) {
    if (len == 0) {
        return NULL;
    }
    int ip;
    for (ip=ins; ip<ins+len-1; ip++) {
        if (inorder[ip] == preorder[pres]) {
            break;
        }
    }
    int ll = ip - ins;
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->val = inorder[ip];
    root->left = build(preorder, pres+1, inorder, ins, ll);
    root->right = build(preorder, pres+ll+1, inorder, ip+1, ins+len-ip-1);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder, 0, inorder, 0, inorderSize);
}
