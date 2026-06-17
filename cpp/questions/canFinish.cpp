#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        for (auto& v: prerequisites) {
            graph[v[0]].push_back(v[1]);
        }
        std::vector<int> flag(numCourses);
        std::function<bool(int)> dfs = [&](int c) -> bool {
            if (flag[c] == 1) {
                return false;
            } else if (flag[c] == 2) {
                return true;
            }
            flag[c] = 1;
            for (auto rc: graph[c]) {
                if (!dfs(rc)) {
                    return false;
                }
            }
            flag[c] = 2;
            return true;
        };
        for (int i=0; i<numCourses; ++i) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
