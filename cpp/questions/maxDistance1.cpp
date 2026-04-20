#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors[n-1]) {
            return n - 1;
        }
        const int& bc = colors[0];
        int ans;
        for (int l=0; l<n; ++l) {
            if (colors[l] == bc) {
                continue;
            }
            ans = std::max(n-1-l, l);
            break;
        }
        for (int r=n-1; r>=0; --r) {
            if (colors[r] == bc) {
                continue;
            }
            ans = std::max(std::max(n-1-r, r), ans);
            break;
        }
        return ans;
    }
};
