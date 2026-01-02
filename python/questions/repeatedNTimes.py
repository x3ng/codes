class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        numcnt = {}
        n = len(nums) // 2
        for num in nums:
            numcnt[num] = numcnt.get(num, 0) + 1
            if numcnt[num] == n:
                return num
        return -1
