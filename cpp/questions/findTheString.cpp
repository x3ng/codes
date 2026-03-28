#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        std::string ans(n, 0);
        int s = 0;
        for (char c='a'; c<='z'; ++c) {
            for (int p=s; p<n; ++p) {
                if (lcp[s][p]) {
                    ans[p] = c;
                }
            }
            while (s < n && ans[s]) {
                ++s;
            }
            if (s == n) {
                break;
            }
        }
        if (s < n) {
            return "";
        }
        for (int r=n-1; r>=0; --r) {
            for (int c=n-1; c>=0; --c) {
                int cp = ans[r]==ans[c] ? (r==n-1 || c==n-1) ? 1 : lcp[r+1][c+1]+1 : 0;
                if (lcp[r][c] != cp) {
                    return "";
                }
            }
        }
        return ans;
    }
};
