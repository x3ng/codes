from typing import List, Optional

class Trie:

    class TNode:
        def __init__(self):
            self.child: List[Optional["Trie.TNode"]] = [None] * 26
            self.is_end: bool = False

    def __init__(self):
        self.root: "Trie.TNode" = self.TNode()

    def _toEnd(self, word: str) -> Optional[TNode]:
        cur: "Trie.TNode" = self.root
        for c in word:
            bias: int = ord(c) - ord('a')
            if cur.child[bias] is None:
                return None
            cur = cur.child[bias]
        return cur

    def insert(self, word: str) -> None:
        cur: "Trie.TNode" = self.root
        for c in word:
            bias: int = ord(c) - ord('a')
            if cur.child[bias] is None:
                cur.child[bias] = self.TNode()
            cur = cur.child[bias]
        cur.is_end = True

    def search(self, word: str) -> bool:
        n = self._toEnd(word)
        if n:
            return n.is_end
        else:
            return False

    def startsWith(self, prefix: str) -> bool:
        n = self._toEnd(prefix)
        return True if n else False
