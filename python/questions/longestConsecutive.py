from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if (len(nums) == 0):
            return 0
        ans = 1
        st = set(nums)
        for n in st:
            if n-1 not in st:
                cn = n
                cl = 1
                while cn+1 in st:
                    cn += 1
                    cl += 1
                ans = max(ans, cl)
        return ans

