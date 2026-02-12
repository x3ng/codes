"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    oc = {}
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        ocr = self.oc.get(node, None)
        if ocr is not None:
            return self.oc[node]
        ccn = Node(node.val)
        self.oc[node] = ccn
        for n in node.neighbors:
            ccn.neighbors.append(self.cloneGraph(n))
        return ccn
