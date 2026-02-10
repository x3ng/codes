class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for s in range(n):
            nst = set([nums[s]])
            d = 1 if nums[s] & 1 else -1
            for e in range(s+1, n):
                cn = nums[e]
                if cn not in nst:
                    nst.add(cn)
                    d += 1 if cn & 1 else -1
                if d == 0:
                    ans = max(ans, e-s+1)
        return ans

