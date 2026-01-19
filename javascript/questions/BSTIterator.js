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
 */
var BSTIterator = function(root) {
    this.ins = [];
    this.pushLeft(root);
};

/**
 * @return {number}
 */
BSTIterator.prototype.next = function() {
    const curn = this.ins.pop();
    this.pushLeft(curn.right);
    return curn.val;
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
    return this.ins.length > 0;
};

BSTIterator.prototype.pushLeft = function(node) {
    while(node != null) {
	this.ins.push(node);
	node = node.left;
    }
};

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
