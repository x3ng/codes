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

function sumNumbers(root: TreeNode | null): number {
    function dfs(pres: number, node: TreeNode | null): number {
	if (node === null) {
	    return 0;
	}
	pres = pres*10 + node.val;
	let lrs = dfs(pres, node.left) + dfs(pres, node.right);
	if (lrs === 0) {
	    return pres;
	} else {
	    return lrs;
	}
    }
    return dfs(0, root);
};
