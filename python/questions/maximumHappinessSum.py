class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        cnt = 1
        ans = happiness[0]
        while cnt < k:
            if happiness[cnt] > cnt:
                ans += happiness[cnt] - cnt
                cnt += 1
            else:
                return ans
