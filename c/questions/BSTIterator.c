/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode** ins;
    int sts;
    int cap;
} BSTIterator;

void pushLeft(BSTIterator* obj, struct TreeNode* node) {
    while (node != NULL) {
        obj->ins[obj->sts++] = node;
        if (obj->sts == obj->cap) {
            obj->cap *= 2;
            obj->ins = (struct TreeNode**)realloc(obj->ins, sizeof(struct TreeNode*)*obj->cap);
        }
        node = node->left;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->sts = 0;
    obj->cap = 2;
    obj->ins = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*obj->cap);
    pushLeft(obj, root);
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* cn = obj->ins[--obj->sts];
    pushLeft(obj, cn->right);
    return cn->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->sts > 0;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->ins);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
