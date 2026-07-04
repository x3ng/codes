from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        lh = len(heights)
        st = [-1]
        ans = 0
        for i, h in enumerate(heights):
            while len(st)>1 and h<=heights[st[-1]]:
                ph = heights[st.pop()]
                ans = max(ans, ph*(i-st[-1]-1))
            st.append(i)
        while len(st)>1:
            ph = heights[st.pop()]
            ans = max(ans, ph*(lh-st[-1]-1))
        return ans
