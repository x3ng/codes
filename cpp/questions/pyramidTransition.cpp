class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        std::unordered_map<std::string, std::string> amp;
        for (std::string& s : allowed) {
            amp[s.substr(0, 2)] += s[2];
        }
        int n = bottom.size();
        std::vector<std::string> pyramid(n);
        for (int i=0; i<n-1; i++) {
            pyramid[i].resize(i+1);
        }
        pyramid[n-1] = std::move(bottom);
        std::unordered_set<std::string> vis;
        std::function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (i == -1) {
                return true;
            }
            if (vis.contains(pyramid[i])) {
                return false;
            }
            if (j == i+1) {
                vis.insert(pyramid[i]);
                return dfs(i-1, 0);
            }
            std::string tmp(1, pyramid[i+1][j]);
            tmp += pyramid[i+1][j+1];
            auto it = amp.find(tmp);
            if (it != amp.end()) {
                for (char c : it->second) {
                    pyramid[i][j] = c;
                    if (dfs(i, j+1)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs(n-2, 0);
    }
};
