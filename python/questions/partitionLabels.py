from typing import List

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ans = []
        fp = [-1] * 26
        for i, c in enumerate(s):
            fp[ord(c)-ord('a')] = i
        cs = 0
        ce = 0
        for i, c in enumerate(s):
            ce = max(ce, fp[ord(c)-ord('a')])
            if i == ce:
                ans.append(ce - cs + 1)
                cs = i + 1
        return ans
