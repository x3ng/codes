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

class BSTIterator {
    private ins: TreeNode[];
    
    private pushLeft(node: TreeNode | null) {
	while (node != null) {
	    this.ins.push(node);
	    node = node.left;
	}
    }
    
    constructor(root: TreeNode | null) {
        this.ins = [];
	this.pushLeft(root);
    }

    next(): number {
        const curn = this.ins.pop();
	this.pushLeft(curn.right);
	return curn.val;
    }

    hasNext(): boolean {
        return this.ins.length > 0;
    }

}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
