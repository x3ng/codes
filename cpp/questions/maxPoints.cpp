#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        return b ? gcd(b, a%b) : a;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int ps = points.size();
        if (ps <= 2) {
            return ps;
        }
        int ans = 0;
        for (int s=0; s<ps; ++s) {
            std::unordered_map<uint64_t, int> lm;
            int sx = points[s][0];
            int sy = points[s][1];
            for (int e=s+1; e<ps; ++e) {
                int dx = points[e][0]-sx;
                int dy = points[e][1]-sy;
                if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                } else if (dy < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                int cd = gcd(dx, dy);
                dx /= cd;
                dy /= cd;
                uint64_t ck = (static_cast<uint64_t>(dx)<<32) | static_cast<uint32_t>(dy);
                lm[ck]++;
                ans = std::max(ans, lm[ck]);
            }
        }
        return ans + 1;
    }
};
