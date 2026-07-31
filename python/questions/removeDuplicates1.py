from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ln = len(nums)
        vp = 0
        sp = 1
        while sp < ln:
            vv = nums[vp]
            vp += 1
            nums[vp] = nums[sp]
            if nums[sp] != vv:
                sp += 1
            else:
                while sp < ln and nums[sp] == vv:
                    sp += 1
        return vp + 1
