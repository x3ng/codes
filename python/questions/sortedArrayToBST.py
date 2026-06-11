from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def bt(l: int, r: int) -> Optional[TreeNode]:
            if l > r:
                return None
            m = (l + r) // 2
            n = TreeNode(nums[m])
            n.left = bt(l, m-1)
            n.right = bt(m+1, r)
            return n
        return bt(0, len(nums)-1)
