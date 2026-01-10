/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (!root) {
        return NULL;
    }
    struct Node* nl[6001];
    nl[0] = root;
    int ls = 0;
    int le = 1;
    int ge = 1;
    int cp;
    struct Node* pre;
    struct Node* cn;
    while (ls < ge) {
        pre = NULL;
        for (cp=ls; cp<le; cp++) {
            cn = nl[cp];
            cn->next = pre;
            pre = cn;
            if (cn->right) {
                nl[ge++] = cn->right;
            }
            if (cn->left) {
                nl[ge++] = cn->left;
            }
        }
        ls = le;
        le = ge;
    }
    return root;
}
