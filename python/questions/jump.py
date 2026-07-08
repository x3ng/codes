from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        ln = len(nums)
        ans = 0
        sp = 0
        ep = 0
        while ep < ln-1:
            ce = sp
            for i in range(sp, ep+1):
                ce = max(ce, i+nums[i])
            sp = ep + 1
            ep = ce
            ans += 1
        return ans
