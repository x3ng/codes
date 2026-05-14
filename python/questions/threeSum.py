from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3:
            return []
        nums.sort()
        ans = []
        for i in range(n-2):
            if nums[i]+nums[i+1]+nums[i+2] > 0:
                break
            if (i>0 and nums[i]==nums[i-1]) or nums[i]+nums[n-2]+nums[n-1] < 0:
                continue
            t = nums[i]
            l = i + 1
            r = n - 1
            while l < r:
                s = t+nums[l]+nums[r]
                if s > 0:
                    r -= 1
                elif s < 0:
                    l += 1
                else:
                    ans.append([t, nums[l], nums[r]])
                    l += 1
                    while l<r and nums[l-1]==nums[l]:
                        l += 1
                    r -= 1
                    while l<r and nums[r]==nums[r+1]:
                        r -= 1
        return ans
