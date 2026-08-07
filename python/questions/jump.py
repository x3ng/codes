from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        ln = len(nums)
        l = 0
        r = 0
        s = 0
        while l <= r:
            if r >= ln - 1:
                return s
            cr = r
            for p in range(l, cr + 1):
                r = max(r, nums[p] + p)
            l = cr + 1
            s += 1
        return -1
