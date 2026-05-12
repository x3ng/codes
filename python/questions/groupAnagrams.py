from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dt = dict()
        for s in strs:
            k = "".join(sorted(s))
            if k in dt:
                dt[k].append(s)
            else:
                dt[k] = [s]
        return [sl for _, sl in dt.items()]
