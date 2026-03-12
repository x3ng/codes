#include <vector>
#include <climits>
#include <functional>

using namespace std;

class Solution {
private:
    class DSU {
    private:
        std::vector<int> parent;
    public:
        int bc;
        
        DSU(int n) : parent(n), bc(n) {
            for (int p=0; p<n; ++p) {
                parent[p] = p;
            }
        }

        int find(int x) {
            return parent[x]==x ? x : (parent[x]=find(parent[x]));
        }

        bool merge(int s, int d) {
            int dr = find(d);
            int sr = find(s);
            if (dr == sr) {
                return false;
            }
            --bc;
            parent[sr] = dr;
            return true;
        }
    };
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU must(n);
        DSU alle(n);
        int maxs = INT_MIN;
        int mins = INT_MAX;
        int minmust = INT_MAX;
        for (const auto& e: edges) {
            int u = e[0], v = e[1], s = e[2], m = e[3];
            if (m) {
                minmust = std::min(minmust, s);
                if (!must.merge(u, v)) {
                    return -1;
                }
            }
            alle.merge(u, v);
            maxs = std::max(maxs, s);
            mins = std::min(mins, s);
        }
        if (alle.bc > 1) {
            return -1;
        }
        std::function<bool(int)> check = [&](int lb) -> bool {
            if (lb > minmust) {
                return false;
            }
            DSU tree = must;
            for (const auto& e: edges) {
                int u = e[0], v = e[1], s = e[2], m = e[3];
                if (m) {
                    continue;
                }
                if (s >= lb) {
                    tree.merge(u, v);
                }
                if (tree.bc == 1) {
                    return true;
                }
            }
            int dt = k;
            for (const auto& e: edges) {
                if (dt==0 || tree.bc==1) {
                    break;
                }
                int u = e[0], v = e[1], s = e[2], m = e[3];
                if (!m && s<lb && 2*s>=lb && tree.merge(u, v)) {
                    --dt;
                }
            }
            return tree.bc == 1;
        };
        int l = mins;
        int r = maxs * 2;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return check(l) ? l : l - 1;
    }
};
