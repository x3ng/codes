class MinStack:

    def __init__(self):
        self.st = [(0, inf)]

    def push(self, val: int) -> None:
        self.st.append((val, min(val, self.st[-1][1])))

    def pop(self) -> None:
        self.st.pop()

    def top(self) -> int:
        return self.st[-1][0]

    def getMin(self) -> int:
        return self.st[-1][1]
