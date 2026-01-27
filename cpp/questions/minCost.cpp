#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<std::pair<int, int>>> sdc(n);    
        for (auto& e: edges) {
            int s = e[0];
            int d = e[1];
            int w = e[2];
            sdc[s].push_back({d, w});
            sdc[d].push_back({s, w*2});
        }
        std::vector<int> gmc(n, std::numeric_limits<int>::max());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        gmc[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [w, d] = pq.top();
            pq.pop();
            if (w > gmc[d]) {
                continue;
            }
            if (d == n-1) {
                return w;
            }
            for (auto& [nd, aw]: sdc[d]) {
                int nw = w + aw;
                if (nw < gmc[nd]) {
                    gmc[nd] = nw;
                    pq.push({nw, nd});
                }
            }
        }
        return -1;
    }
};
