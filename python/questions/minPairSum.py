class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        nums.sort()
        ans = -inf
        while l < r:
            ans = max(ans, nums[l]+nums[r])
            l += 1
            r -= 1
        return ans
