/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* build(int* inm, int* inorder, int ine, int* postorder, int poste, int len) {
    if (len == 0) {
        return NULL;
    }
    int ip = inm[postorder[poste]+3000];
    int rl = ine - ip;
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = postorder[poste];
    node->left = build(inm, inorder, ip-1, postorder, poste-rl-1, len-rl-1);
    node->right = build(inm, inorder, ine, postorder, poste-1, rl);
    return node;
}
    
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int* inm = (int*) malloc(sizeof(int) * 6000);
    for (int p=0; p<inorderSize; p++) {
        inm[inorder[p]+3000] = p;
    }
    return build(inm, inorder, inorderSize-1, postorder, postorderSize-1, inorderSize);
}
