from typing import Optional

class LRUCache:

    class DualListNode:
        def __init__(self, val: int=0, prev: Optional["DualListNode"]=None, next: Optional["DualListNode"]=None):
            self.val = val
            self.prev = prev
            self.next = next

    def __init__(self, capacity: int):
        self.cap = capacity
        self.kvm = {}
        self.knm = {}
        self.lnh = self.DualListNode(0)
        self.lnt = self.DualListNode(0)
        self.lnh.next = self.lnt
        self.lnt.prev = self.lnh

    def get(self, key: int) -> int:
        if key in self.kvm:
            cn = self.knm[key]
            cn.prev.next = cn.next
            cn.next.prev = cn.prev
            self.lnt.prev.next = cn
            cn.prev = self.lnt.prev
            cn.next = self.lnt
            self.lnt.prev = cn
            return self.kvm[key]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.get(key) != -1:
            self.kvm[self.lnt.prev.val] = value
            return
        if len(self.kvm) < self.cap:
            nn = self.DualListNode(key, self.lnt.prev, self.lnt)
            self.lnt.prev.next = nn
            self.lnt.prev = nn
            self.kvm[key] = value
            self.knm[key] = nn
        else:
            mn = self.lnh.next
            self.lnh.next = mn.next
            mn.next.prev = self.lnh
            mn.next = self.lnt
            mn.prev = self.lnt.prev
            self.lnt.prev.next = mn
            self.lnt.prev = mn
            self.knm[key] = self.knm.pop(mn.val)
            self.kvm.pop(mn.val)
            self.kvm[key] = value
            mn.val = key

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
