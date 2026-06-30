from typing import List

class MinStack:

    def __init__(self):
        self.st: List[tuple[int, int]] = []

    def push(self, value: int) -> None:
        if not self.st:
            mv = value
        else:
            mv = min(self.st[-1][1], value)
        self.st.append((value, mv))

    def pop(self) -> None:
        self.st.pop()        

    def top(self) -> int:
        return self.st[-1][0] 

    def getMin(self) -> int:
        return self.st[-1][1] 

