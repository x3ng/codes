from __future__ import annotations
from typing import Optional

class LRUCache:

    class Node:
        def __init__(self, k: int, v: int, p: Optional[Node], n: Optional[Node]):
            self.k = k
            self.v = v
            self.p = p
            self.n = n

    def __init__(self, capacity: int):
        self.cap = capacity        
        self.dt = {}
        self.h = self.Node(0, 0, None, None)
        self.t = self.Node(0, 0, self.h, None)
        self.h.n = self.t

    def _freshNode(self, n: Node) -> None:
        n.n.p = n.p
        n.p.n = n.n
        n.p = self.h
        n.n = self.h.n
        n.n.p = n
        self.h.n = n

    def get(self, key: int) -> int:
        cn = self.dt.get(key, None) 
        if cn is None:
            return -1
        self._freshNode(cn)
        return cn.v

    def put(self, key: int, value: int) -> None:
        if self.get(key) != -1:
            self.h.n.v = value
        elif self.cap:
            self.cap -= 1
            nn = self.Node(key, value, self.h, self.h.n)
            nn.n.p = nn
            self.h.n = nn
            self.dt[key] = nn
        else:
            on = self.t.p
            self._freshNode(on)
            ok = on.k
            self.dt.pop(ok)
            self.dt[key] = on
            on.k = key
            on.v = value
