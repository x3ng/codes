class Solution:
    def longestBalanced(self, s: str) -> int:
        ans = 0
        ss = len(s)
        for l in range(ss):
            cnt = defaultdict(int)
            for r in range(l, ss):
                cnt[s[r]] += 1
                if len(set(cnt.values())) == 1:
                    ans = max(ans, r-l+1)
        return ans
