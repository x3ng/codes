class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        s1s = len(s1)
        s2s = len(s2)
        rs = [0 for _ in range(s1s+1)]
        total = sum(map(ord, s1)) + sum(map(ord, s2))
        for p2 in range(s2s):
            pre = 0
            for p1 in range(s1s):
                if s1[p1] == s2[p2]:
                    tmp = pre + ord(s1[p1])
                    pre = rs[p1+1]
                else:
                    tmp = max(rs[p1], rs[p1+1])
                    pre = rs[p1+1]
                rs[p1+1] = tmp
        return total-rs[s1s]*2
