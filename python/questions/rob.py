from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        ln = len(nums)
        cm = [[0, 0] for _ in range(ln+1)]
        cm[1] = [nums[0], nums[0]]
        for i in range(1, ln):
            cm[i+1][0] = cm[i-1][1] + nums[i]
            cm[i+1][1] = max(cm[i+1][0], cm[i][1])
        return cm[ln][1]
