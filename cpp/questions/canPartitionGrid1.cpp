#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private: 
    template<typename T>
    std::vector<std::vector<T>> rotateMatrix(std::vector<std::vector<T>>& m) {
        int mr = m.size();
        int mc = m[0].size();
        std::vector<std::vector<T>> rm(mc, std::vector<T>(mr));
        for (int r=0; r<mr; ++r) {
            for (int c=0; c<mc; ++c) {
                rm[c][mr-r-1] = m[r][c];
            }
        }
        return rm;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int gr = grid.size();
        int gc = grid[0].size();
        long long total = 0;
        for (int r=0; r<gr; ++r) {
            for (int c=0; c<gc; ++c) {
                total += grid[r][c];
            }
        }
        auto check = [&total](std::vector<std::vector<int>>& m) {
            int mr = m.size();
            int mc = m[0].size();
            std::unordered_set<long long> hm{0};
            long long cs = 0;
            for (int r=0; r<mr; ++r) {
                const auto& cr = m[r];
                for (int c=0; c<mc; ++c) {
                    const auto& cv = cr[c];
                    cs += cv;
                    if (r>0 || c==0 || c==mc-1) {
                        hm.insert(cv);
                    }
                }
                if (mc == 1) {
                    int ct = 2 * cs - total;
                    if (ct == 0 || m[0][0] == ct || m[r][0] == ct) {
                        return true;
                    }
                    continue;
                }
                if (hm.find(2*cs - total) != hm.end()) {
                    return true;
                }
                if (r == 0) {
                    for (const auto& v: cr) {
                        hm.insert(v);
                    }
                }
            }
            return false;
        };
        if (check(grid)) {
            return true;
        }
        auto cm = grid;
        for (int rc=0; rc<3; ++rc) {
            cm = rotateMatrix(cm);
            if (check(cm)) {
                return true;
            }
        }
        return false;
    }
};
