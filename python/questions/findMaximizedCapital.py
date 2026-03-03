class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n = len(capital)
        pj = [(capital[i], profits[i]) for i in range(n)]
        pj.sort(key = lambda x: x[0])
        phq = []
        p = 0
        while k > 0:
            k -= 1
            while p<n and w>=pj[p][0]:
                heapq.heappush(phq, -pj[p][1])
                p += 1
            if not phq:
                break
            w -= heapq.heappop(phq)
        return w
