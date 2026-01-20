class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [-1 for _ in range(n)]
        for p in range(n):
            if nums[p] & 1:
                tmp = nums[p]
                cnt = 0
                while tmp & 1:
                    cnt += 1
                    tmp >>= 1
                ans[p] = nums[p] & ~(1<<(cnt-1))
        return ans
