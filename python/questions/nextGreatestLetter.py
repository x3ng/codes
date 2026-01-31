from typing import List

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l = 0
        r = len(letters) - 1
        if letters[0] > target or letters[r] <= target:
            return letters[0]
        while l < r:
            m = (l + r) // 2
            if letters[m] > target:
                r = m
            else:
                l = m + 1
        return letters[l]
