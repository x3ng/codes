class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> stat(numCourses, 0);
        std::vector<std::vector<int>> edges(numCourses);
        bool valid = true;
        for (const auto& p: prerequisites) {
            edges[p[0]].push_back(p[1]);
        }
        std::vector<int> ans(numCourses);
        int rp = 0;
        auto dfs = [&](this auto&& dfs, int cn) -> void {
            stat[cn] = 1;
            for (const auto& nn: edges[cn]) {
                if (stat[nn] == 0) {
                    dfs(nn);
                    if (valid == false) {
                        return;
                    }
                } else if (stat[nn] == 1) {
                    valid = false;
                    return;
                }
            }
            stat[cn] = 2;
            ans[rp++] = cn;
        };
        for (int p=0; p<numCourses; p++) {
            if (stat[p] == 0) {
                dfs(p);
            }
            if (valid == false) {
                break;
            }
        }
        if (valid == false) {
            return {};
        } else {
            return ans;
        }
    }
};
