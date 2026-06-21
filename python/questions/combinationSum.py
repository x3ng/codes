from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        lc = len(candidates)
        ans = []
        tmp = []
        def bc(p: int, tgt: int) -> None:
            if tgt == 0:
                ans.append(tmp.copy())
                return
            elif tgt < 0:
                return
            for np in range(p, lc):
                tmp.append(candidates[np])
                bc(np, tgt-candidates[np])
                tmp.pop()
        bc(0, target)
        return ans
