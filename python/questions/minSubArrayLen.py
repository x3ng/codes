from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ws = 0
        l = 0
        ans = len(nums) + 1
        for r, v in enumerate(nums):
            ws += v
            if ws >= target:
                while ws >= target:
                    ws -= nums[l]
                    l += 1
                ans = min(ans, r-l+2)
        return ans if ans!=len(nums)+1 else 0
