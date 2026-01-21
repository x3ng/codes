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

function countNodes(root: TreeNode | null): number {
    if (root === null) {
	return 0;
    }
    const nodeExist = (root: TreeNode, level: number, nid: number): boolean => {
	let bs = 1 << (level - 1);
	let node = root;
	while (bs) {
	    if (bs & nid) {
		node = node.right;
	    } else {
		node = node.left;
	    }
	    bs >>= 1;
	}
	return node != null;
    };
    let level = 0;
    let node = root;
    while (node.left) {
	node = node.left;
	level++;
    }
    let minn = 1 << level;
    let maxn = (1 << (level + 1)) - 1;
    while (minn < maxn) {
	const midn = Math.ceil((minn + maxn + 1) / 2);
	if (nodeExist(root, level, midn)) {
	    minn = midn;
	} else {
	    maxn = midn - 1;
	}
    }
    return minn;
};
