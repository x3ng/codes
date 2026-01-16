class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        MOD = 10**9 + 7
        def addBorderSort(fences: List[int], border: int) -> void:
            fences.append(1)
            fences.append(border)
            fences.sort()
        addBorderSort(hFences, m)
        addBorderSort(vFences, n)
        hvd = {}
        maxb = 0;
        for h in hFences:
            for v in vFences:
                curhv = h - v
                if curhv in hvd:
                    maxb = max(maxb, h-hvd[curhv])
                else:
                    hvd[curhv] = h
        return (maxb**2)%MOD if maxb!=0 else -1 
