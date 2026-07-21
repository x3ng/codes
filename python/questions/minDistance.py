from functools import cache

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        l1 = len(word1)
        l2 = len(word2)
        @cache
        def dfs(p1: int, p2: int) -> int:
            if p1 < 0:
                return p2 + 1
            if p2 < 0:
                return p1 + 1
            if word1[p1] == word2[p2]:
                return dfs(p1-1, p2-1)
            else:
                return min(dfs(p1-1, p2), dfs(p1, p2-1), dfs(p1-1, p2-1)) + 1
        return dfs(l1-1, l2-1)
