/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function maxPathSum(root: TreeNode | null): number {
    let maxSum: number = Number.NEGATIVE_INFINITY;
    const dfs = (node: TreeNode | null): number => {
	if (node === null) {
	    return 0;
	}
	const l = Math.max(dfs(node.left), 0);
	const r = Math.max(dfs(node.right), 0);
	maxSum = Math.max(maxSum, node.val+l+r);
	return Math.max(l, r)+node.val;
    }
    dfs(root);
    return maxSum;
};
