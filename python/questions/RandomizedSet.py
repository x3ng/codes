import random


class RandomizedSet:

    def __init__(self):
        self.dt = {}
        self.v = []

    def insert(self, val: int) -> bool:
        idx = self.dt.get(val, -1)
        if idx == -1:
            self.dt[val] = len(self.v)
            self.v.append(val)
            return True
        return False

    def remove(self, val: int) -> bool:
        idx = self.dt.get(val, -1)
        if idx == -1:
            return False
        self.v[idx] = self.v[-1]
        self.dt[self.v[-1]] = idx
        self.dt.pop(val)
        self.v.pop()
        return True

    def getRandom(self) -> int:
        return self.v[random.randrange(len(self.v))]
