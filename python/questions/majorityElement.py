from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        v = 0
        s = 0
        for n in nums:
            if v == 0:
                s = n
            v += 1 if n==s else -1
        return s
