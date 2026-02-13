class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool valid = true;
        std::vector<int> visited(numCourses, 0);
        std::vector<std::vector<int>> edges(numCourses);
        for (const auto& p: prerequisites) {
            edges[p[0]].push_back(p[1]);
        }
        auto dfs = [&](this auto&& dfs, int ec) -> void {
            visited[ec] = true;
            for (const auto& nc: edges[ec]) {
                if (visited[nc] == 0) {
                    dfs(nc);
                    if (valid == false) {
                        return;
                    }
                } else if (visited[nc] == 1) {
                    valid = false;
                    return;
                }
            }
            visited[ec] = 2;
        };
        for (int c=0; c<numCourses; c++) {
            if (visited[c] == false) {
                dfs(c);
            }
            if (valid == false) {
                break;
            }
        }
        return valid;
    }
};
