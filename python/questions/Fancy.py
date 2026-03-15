class Fancy:
    MOD = 1_000_000_007

    def __init__(self):
        self.add = 0
        self.mul = 1
        self.ele = []

    def append(self, val: int) -> None:
        self.ele.append((val-self.add) * pow(self.mul, self.MOD-2, self.MOD) % self.MOD)
         

    def addAll(self, inc: int) -> None:
        self.add += inc 

    def multAll(self, m: int) -> None:
        self.mul = self.mul * m % self.MOD
        self.add = self.add * m % self.MOD
        

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.ele):
            return -1
        return (self.ele[idx] * self.mul + self.add) % self.MOD
        


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)
