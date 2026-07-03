from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        lt = len(temperatures)
        st = []
        ans = [0] * lt
        for p in range(lt):
            ct = temperatures[p]
            while len(st) and ct>st[-1][0]:
                _, pp = st.pop()
                ans[pp] = p - pp
            st.append(([ct, p]))
        return ans
