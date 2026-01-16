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
var maxPathSum = function(root) {
    let maxSum = Number.NEGATIVE_INFINITY;
    const dfs = function(node) {
	if (node === null) {
	    return 0;
	}
	const l = Math.max(dfs(node.left), 0);
	const r = Math.max(dfs(node.right), 0);
	maxSum = Math.max(maxSum, node.val+l+r);
	return Math.max(l, r) + node.val;
    }
    dfs(root);
    return maxSum;
};
