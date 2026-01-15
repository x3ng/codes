/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumNumbers = function(root) {
    let dfs = function(pres, node) {
	if (node === null) {
	    return 0;
	}
	pres = pres*10 + node.val;
	let lrs = dfs(pres, node.left) + dfs(pres, node.right);
	if (lrs == 0) {
	    return pres;
	} else {
	    return lrs;
	}
    }
    return dfs(0, root);
};
