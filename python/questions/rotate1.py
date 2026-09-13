from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        ln = len(nums)
        def reverse(i: int, j: int) -> None:
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
        k %= ln
        reverse(0, ln-1)
        reverse(0, k-1)
        reverse(k, ln-1)
