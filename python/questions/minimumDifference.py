class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(nums[p]-nums[p-k+1] for p in range(k-1, len(nums)))
