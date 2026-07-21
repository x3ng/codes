class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        l1 = len(text1)
        l2 = len(text2)
        ls = [0] * l1
        for i in range(l2):
            tl = ls.copy()
            ls[0] = 1 if ls[0]==1 or text2[i]==text1[0] else 0
            for j in range(1, l1):
                if text2[i] == text1[j]:
                    ls[j] = 1 + tl[j-1]
                else:
                    ls[j] = max(ls[j-1], tl[j])
        return ls[-1]

