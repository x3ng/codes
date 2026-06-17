from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        for cs in prerequisites:
            graph[cs[0]].append(cs[1])
        flag = [0 for _ in range(numCourses)]
        def dfs(c: int) -> bool:
            if flag[c] == 1:
                return False
            elif flag[c] == 2:
                return True
            flag[c] = 1
            for nc in graph[c]:
                if not dfs(nc):
                    return False
            flag[c] = 2
            return True
        for i in range(numCourses):
            if not dfs(i):
                return False
        return True
