import heapq

class MedianFinder:

    def __init__(self):
        self.gq = []
        self.lq = []

    def addNum(self, num: int) -> None:
        if len(self.lq) <= len(self.gq):
            heapq.heappush(self.lq, -num)
        else:
            heapq.heappush(self.gq, num)
        if not len(self.lq) or not len(self.gq):
            return
        while -self.lq[0] > self.gq[0]:
            lt = -heapq.heappop(self.lq)
            gt = heapq.heappop(self.gq)
            heapq.heappush(self.lq, -gt)
            heapq.heappush(self.gq, lt)

    def findMedian(self) -> float:
        if len(self.lq) == len(self.gq):
            return (self.gq[0] - self.lq[0]) / 2
        else:
            return -self.lq[0]

