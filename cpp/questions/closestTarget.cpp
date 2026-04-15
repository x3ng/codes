#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int l = startIndex;
        int r = startIndex;
        int ans = 0;
        for (ans=0; ans<=n/2; ++ans) {
            if (words[l]==target || words[r]==target) {
                return ans;
            }
            l = (l + n - 1) % n;
            r = (r + 1) % n;
        }
        return -1;
    }
};
