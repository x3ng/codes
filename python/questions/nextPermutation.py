from typing import List

class Solution:

    def fb(self, l: List[int], b: int, e: int, t: int) -> int:
        while b < e:
            m = (b + e + 1) // 2
            if l[m] > t:
                b = m
            else:
                e = m - 1
        return b

    def nextPermutation(self, nums: List[int]) -> None:
        ln = len(nums)
        p = ln - 1
        while p>0 and nums[p]<=nums[p-1]:
            p -= 1
        if p:
            bp = self.fb(nums, p, ln-1, nums[p-1])
            nums[p-1], nums[bp] = nums[bp], nums[p-1]
        l = p
        r = ln - 1
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
