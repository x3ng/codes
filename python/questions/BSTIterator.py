# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
     
    def __init__(self, root: Optional[TreeNode]):
        self.ins = []
        self.pushLeft(root)
        
    def next(self) -> int:
        curn = self.ins[-1]
        self.ins.pop()
        self.pushLeft(curn.right)
        return curn.val

    def hasNext(self) -> bool:
        return len(self.ins) > 0

    def pushLeft(self, node: Optional[TreeNode]):
        if node is None:
            return
        self.ins.append(node)
        self.pushLeft(node.left)
# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
