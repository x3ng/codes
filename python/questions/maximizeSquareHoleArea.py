class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        def getmc(Bars: List[int]) -> int:
            mc = 2
            cc = 2
            prev = Bars[0]
            for p in range(1, len(Bars)):
                curr = Bars[p]
                if curr == prev+1:
                    cc += 1
                else:
                    mc = max(mc, cc)
                    cc = 2
                prev = curr
            mc = max(mc, cc)
            return mc
        hBars.sort()
        vBars.sort()
        return min(getmc(hBars), getmc(vBars))**2
