#include <vector>
#include <unordered_map>

using namespace std;

const int MX = 1'000'001;
std::vector<int> pfs[MX];

int init = [] {
    for (int i=2; i<MX; ++i) {
        if (pfs[i].empty()) {
            for (int j=i; j<MX; j+=i) {
                pfs[j].push_back(i);
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, std::vector<int>> ji;
        for (int i=0; i<n; ++i) {
            for (const int pf: pfs[nums[i]]) {
                ji[pf].push_back(i);
            }
        }
        std::vector<bool> vis(n, false);
        std::vector<int> sp = {0};
        vis[0] = true;
        for (int ans=0; ; ++ans) {
            std::vector<int> np;
            for (const auto& p: sp) {
                if (p == n-1) {
                    return ans;
                }
                if (!vis[p+1]) {
                    np.push_back(p + 1);
                    vis[p+1] = true;
                }
                if (p>0 && !vis[p-1]) {
                    np.push_back(p - 1);
                    vis[p-1] = true;
                }
                for (const auto i: ji[nums[p]]) {
                    if (!vis[i]) {
                        np.push_back(i);
                        vis[i] = true;
                    }
                }
                ji[nums[p]].clear();
            }
            sp = np;
        }
        return -1;
    }
};
