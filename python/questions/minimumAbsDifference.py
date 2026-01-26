from typing import List

class Solution:
    def minimumabsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort(reverse=False)
        ans = []
        mad = float('inf')
        for p in range(1, len(arr)):
            curd = arr[p] - arr[p-1]
            if curd == mad:
                ans.append([arr[p-1], arr[p]])
            elif curd < mad:
                mad = curd
                ans.clear()
                ans.append([arr[p-1], arr[p]])
        return ans
