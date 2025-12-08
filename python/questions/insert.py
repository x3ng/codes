class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        s = newInterval[0]
        e = newInterval[1]
        p = 0;
        ans = [];
        while (p<len(intervals) and intervals[p][1]<s):
            ans.append(intervals[p])
            p = p + 1
        if (p < len(intervals)):
            s = min(s, intervals[p][0])
        while (p<len(intervals) and intervals[p][0]<=e):
            e = max(e, intervals[p][1])
            p = p + 1
        ans.append([s, e])
        while (p<len(intervals)):
            ans.append(intervals[p])
            p = p + 1
        return ans
